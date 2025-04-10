from flask import Flask, request, jsonify, send_from_directory
from flask_cors import CORS
import csv
import os

app = Flask(__name__)
CORS(app)  # Enable CORS

# Define path for reports folder
REPORTS_FOLDER = 'reports'

def save_to_csv(filename, data):
    os.makedirs('paths', exist_ok=True)
    file_path = os.path.join('paths', filename)
    with open(file_path, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Latitude', 'Longitude'])
        for point in data:
            writer.writerow([point['lat'], point['lng']])

@app.route('/coordinates', methods=['POST'])
def receive_coordinates():
    data = request.json
    coordinates = data.get('coordinates', [])
    print("Received Coordinates:", coordinates)
    save_to_csv('coordinates.csv', coordinates)
    return jsonify({"message": "Coordinates received and saved", "coordinates": coordinates})

@app.route('/lawnmower_path', methods=['POST'])
def receive_lawnmower_path():
    data = request.json
    path = data.get('lawnmower_path', [])
    print("Received Lawnmower Path:", path)
    save_to_csv('lawnmower_path.csv', path)
    return jsonify({"message": "Lawnmower path received and saved", "path": path})

# New route to serve CSV files from the reports folder
@app.route('/reports/<filename>', methods=['GET'])
def get_report(filename):
    report_path = os.path.join(REPORTS_FOLDER, filename)
    if os.path.exists(report_path):
        return send_from_directory(REPORTS_FOLDER, filename)
    else:
        return jsonify({"message": "Report not found"}), 404
    
@app.route('/reports', methods=['GET'])
def list_reports():
    try:
        # Get a list of all CSV files in the reports folder
        report_files = [f for f in os.listdir(REPORTS_FOLDER) if f.endswith('.csv')]
        return jsonify(report_files)
    except Exception as e:
        return jsonify({"message": "Error reading reports", "error": str(e)}), 500

@app.route('/set_home_base', methods=['POST'])
def set_home_base():
    data = request.json
    point = data.get('home_base', {})
    if not point:
        return jsonify({"message": "No home base data provided"}), 400

    os.makedirs('home_base_point', exist_ok=True)
    file_path = os.path.join('home_base_point', 'home_base.csv')
    with open(file_path, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([point['lat'], point['lng']])

    print("Home base saved:", point)
    return jsonify({"message": "Home base point saved", "home_base": point})

if __name__ == '__main__':
    # Listen on all interfaces so other devices on the same network can reach it
    app.run(host='0.0.0.0', port=8000)
