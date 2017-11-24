
//#include "Text.h"
//
//Text::Text(const std::string newText, const Vector2D& newPosition, SDL_Renderer* ref, const float& textSize, const bool& cent) : text(newText),
//pos(newPosition),
//reference(ref),
//center(cent) {
//	font = TTF_OpenFont("../res/font.ttf", textSize); //this opens a font style and sets a size
//	if (font == NULL){
//		std::cout << "Can't load the font, Error: " << TTF_GetError() << std::endl;
//	}
//}
//
//Text::~Text() {
//}
//
//void Text::RenderText() {
//
//	SDL_Color Color = { 255, 255, 255 };
//
//	surface = TTF_RenderText_Solid(font, text.c_str(), Color);
//	texture = SDL_CreateTextureFromSurface(reference, surface);
//
//	SDL_Rect Message_rect;
//	if (center) {
//		Message_rect.x = pos.x - surface->w / 2;
//		Message_rect.y = pos.y - surface->h / 2;
//	}
//	else {
//		Message_rect.x = pos.x;
//		Message_rect.y = pos.y;
//	}
//	Message_rect.w = surface->w;
//	Message_rect.h = surface->h;
//
//	SDL_RenderCopy(reference, texture, NULL, &Message_rect);
//
//	SDL_DestroyTexture(texture);
//	SDL_FreeSurface(surface);
//}