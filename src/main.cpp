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
        T& request(std::string path)
        {
            auto& map = std::get<std::unordered_map<std::string, std::unique_ptr<T>>>(m_caches);
            if (map.find(path) == map.end())
            {
                map.insert({path,std::move(std::unique_ptr<T>(new T{}))});
                return (*(map.at(path))) ;
            }
            else
                {return *(map.at(path));}
        }
    template<typename T>
        void unload()
        {

            auto& mapa = std::get<std::unordered_map<std::string, std::unique_ptr<Texture>>>(m_caches);
            auto& mapb = std::get<std::unordered_map<std::string, std::unique_ptr<SoundEffect>>>(m_caches);
            mapa.clear();
            mapb.clear();
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
    friend T& ResourceManager::request(std::string path);
    friend struct std::default_delete<Texture>;
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
    friend T& ResourceManager::request(std::string path);
    friend struct std::default_delete<SoundEffect>;
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
    ResourceManager resourcemanager;
    resourcemanager.request<Texture>("player.png");
    resourcemanager.request<SoundEffect>("player.png");
}