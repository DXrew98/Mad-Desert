#include "Animations.h"
#include "sfwdraw.h"
#include <map>

static std::map<std::string, unsigned> textures;

void loadTexture(const std::string &name, const char *path, unsigned r, unsigned c) {
	textures[name] = sfw::loadTextureMap(path, r, c);
}

unsigned getTexture(const std::string &name) {
	return textures[name];
}
