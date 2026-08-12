#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <tuple>
class Texture;
class SoundEffect;
class ResourceManager
{
    public:
    template <typename T>
        T& load(std::string& path)
        {
            auto& map = std::get<std::unordered_map<std::string, std::unique_ptr<T>>>(m_caches);
            map.insert({path,std::move(std::unique_ptr<T>(T{}))});
            return (*(map.at(path))) ;
        }
    private:
        std::tuple
        <
            std::unordered_map<std::string,std::unique_ptr<Texture>> ,
            std::unordered_map<std::string, std::unique_ptr<SoundEffect>>
        > m_caches;
};
class Texture
{
    template <typename T>
    friend T& ResourceManager::load(std::string& path);
private:
    Texture()
    {
        std::cout << "Texture constructed.\n";
    }
    ~Texture()
    {
        std::cout << "Texture destructed.\n";
    }
};

class SoundEffect
{
    template <typename T>
    friend T& ResourceManager::load(std::string& path);
    private:
    SoundEffect()
    {
        std::cout << "SoundEffect constructed.\n";
    }
    ~SoundEffect()
    {
        std::cout << "SoundEffect destructed.\n";
    }
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