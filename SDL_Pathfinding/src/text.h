//#pragma once
//#include <string>
//#include <iostream>
//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
//#include "Vector2D.h"
//
//
//class Text {
//private:
//	std::string text;
//	Vector2D pos;
//	SDL_Surface* surface;
//	SDL_Texture* texture;
//	TTF_Font* font;
//	SDL_Renderer* reference;
//	bool center;
//public:
//	Text(const std::string, const Vector2D&, SDL_Renderer*, const float&, const bool&);
//	~Text();
//	inline std::string GetText() { return text; }
//	inline void SetText(const std::string& newText) { text = newText; }
//	inline Vector2D GetPosition() { return pos; }
//	inline void SetPosition(const Vector2D& newPosition) { pos = newPosition; }
//	void RenderText();
//};