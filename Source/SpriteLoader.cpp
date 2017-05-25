#include "SpriteLoader.h"

void SpriteLoader::load(std::string filename)
{
    if(!texture.loadFromFile(filename))
    {
        MessageBox(NULL,"Texture not found","ERROR",NULL);
    }
    else
    {
        texture.setSmooth(false);
        sprite.setTexture(texture);
    }
}
