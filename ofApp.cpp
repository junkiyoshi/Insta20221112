#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	this->mesh.clear();

	int span = 1;
	ofColor color;
	int len = 580;

	for (int x = len * -0.5; x < len * 0.5; x += span) {

		for (int y = len * -0.5; y < len * 0.5; y += span) {

			int noise_value = ofMap(ofNoise(x * 0.005, y * 0.005 + ofGetFrameNum() * 0.01, ofGetFrameNum() * 0.01), 0, 1, 0, 10);

			if (noise_value % 2 == 0) {

				continue;
			}

			this->mesh.addVertex(glm::vec3(x, y, 0));
			this->mesh.addVertex(glm::vec3(x + span, y, 0));
			this->mesh.addVertex(glm::vec3(x + span, y + span, 0));
			this->mesh.addVertex(glm::vec3(x, y + span, 0));

			this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 4); this->mesh.addIndex(this->mesh.getNumVertices() - 3);
			this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 2); this->mesh.addIndex(this->mesh.getNumVertices() - 3);

			color.setHsb(ofMap(noise_value, 0, 10, 0, 255), 130, 255);
			for (int i = 0; i < 4; i++) {

				this->mesh.addColor(color);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	this->mesh.draw();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}