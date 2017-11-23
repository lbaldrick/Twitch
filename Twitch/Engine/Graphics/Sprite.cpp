#include "Sprite.h"

Sprite::Sprite() {
	xPos = 0;
	yPos = 0;
	rot = 0;
	texture = Texture();
}

Sprite::Sprite(string imagePath) {
	xPos = 0;
	yPos = 0;
	rot = 0;
	texture = Texture(imagePath);
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos) {
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	texture = Texture(imagePath);
}

void Sprite::update() {
	rot++;
}

void Sprite::render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getId());
	glLoadIdentity();

	//Translate -> rotate -> scale
	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);

	//rotate
	//scale

	//Rendering 
	glColor4f(1, 1, 1, 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(0, yPos);
	glTexCoord2f(1, 0);  glVertex2f(texture.getWidth(), 0);
	glTexCoord2f(1, 1);  glVertex2f(texture.getWidth(), texture.getHeight());
	glTexCoord2f(0,1);  glVertex2f(0, texture.getHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::setPos(float _xPos, float _yPos) {
	xPos = _xPos;
	yPos = _yPos;
}

void Sprite::setRot(float _rot) {
	rot = _rot;
}