#include <iostream>


class Texture
{
    public:
    Texture()
    {
        std::cout << "Texture constructed.";
    }
    ~Texture()
    {
        std::cout << "Texture deconstructed";
    }
};

class SoundEffect
{
    public:
    SoundEffect()
    {
        std::cout << "SoundEffect constructed.";
    }
    ~SoundEffect()
    {
        std::cout << "SoundEffect deconstructed";
    }
};