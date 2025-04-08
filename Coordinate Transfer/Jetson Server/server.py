from flask import Flask, request, jsonify
from flask_cors import CORS
import csv
import os

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

# Function to save coordinates or path to a CSV file in the 'paths' folder
def save_to_csv(filename, data):
    # Ensure the 'paths' directory exists
    os.makedirs('paths', exist_ok=True)

    # Define the full file path
    file_path = os.path.join('paths', filename)

    with open(file_path, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Latitude', 'Longitude'])  # Write header
        for point in data:
            writer.writerow([point['lat'], point['lng']])  # Write each coordinate

@app.route('/coordinates', methods=['POST'])
def receive_coordinates():
    data = request.json
    coordinates = data.get('coordinates', [])
    print("Received Coordinates:", coordinates)

    # Save the coordinates to a CSV file in the 'paths' folder
    save_to_csv('coordinates.csv', coordinates)

    return jsonify({"message": "Coordinates received and saved", "coordinates": coordinates})

@app.route('/lawnmower_path', methods=['POST'])
def receive_lawnmower_path():
    data = request.json
    lawnmower_path = data.get('lawnmower_path', [])
    print("Lawnmower Path Coordinates:", lawnmower_path)

    # Save the lawnmower path to a CSV file in the 'paths' folder
    save_to_csv('lawnmower_path.csv', lawnmower_path)

    return jsonify({"message": "Lawnmower path received and saved", "path": lawnmower_path})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8000)
