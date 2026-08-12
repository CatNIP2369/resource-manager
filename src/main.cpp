#include <iostream>
#include <string>
#include <unordered_map>
class Texture;
class SoundEffect;
class ResourceManager
{
    public:
    template <typename T>
        T* load(std::string& path);
    private:
        std::unordered_map<std::string,Texture > textures;
        std::unordered_map<std::string, SoundEffect> soundeffects;

};
class Texture
{
    template <typename T>
    friend T* ResourceManager::load(std::string& path);
private:
    Texture(std::string path)
    : m_path(path)
    {
        std::cout << "Texture constructed.\n";
    }
    ~Texture()
    {
        std::cout << "Texture destructed.\n";
    }
    std::string m_path;
};

class SoundEffect
{
    template <typename T>
    friend T* ResourceManager::load(std::string& path);
    private:
    SoundEffect(std::string path)
    : m_path(path)
    {
        std::cout << "SoundEffect constructed.\n";
    }
    ~SoundEffect()
    {
        std::cout << "SoundEffect destructed.\n";
    }
    std::string m_path;
};





class RenderSystem
{

};
class AudioSystem
{

};
class Entity
{

};

int main()
{

}