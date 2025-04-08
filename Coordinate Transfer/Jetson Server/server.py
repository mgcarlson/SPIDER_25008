from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

@app.route('/coordinates', methods=['POST'])
def receive_coordinates():
    data = request.json
    coordinates = data.get('coordinates', [])
    print("Received Coordinates:", coordinates)
    return jsonify({"message": "Coordinates received", "coordinates": coordinates})

@app.route('/lawnmower_path', methods=['POST'])
def receive_lawnmower_path():
    data = request.json
    lawnmower_path = data.get('lawnmower_path', [])
    print("Lawnmower Path Coordinates:", lawnmower_path)
    return jsonify({"message": "Lawnmower path received", "path": lawnmower_path})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8000)
