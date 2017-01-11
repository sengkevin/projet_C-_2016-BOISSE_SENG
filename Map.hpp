#include <SFML/Graphics.hpp>

class Map : public sf::Drawable, public sf::Transformable{
public:

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_texture;
}
