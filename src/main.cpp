
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create our game window
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "SamGame - Sprite Test"
    );

    window.setFramerateLimit(60);

    // Load Sam's image into a texture
sf::RectangleShape testRectangle({100.f, 100.f});
testRectangle.setFillColor(sf::Color::Red);
testRectangle.setPosition({100.f, 100.f});

sf::Texture texture;

std::cout << "Attempting to load Sam...\n";

if (!texture.loadFromFile(
    "assets/sprites/walk/left/walk2 LEFT1.png"))
{
    std::cerr << "ERROR: Could not load sprite!\n";
    return -1;
}

std::cout << "SUCCESS: Sam's texture loaded!\n";


    // Keep pixel art sharp when scaled
    texture.setSmooth(false);

    

    // Create a sprite using the texture
    sf::Sprite sam(texture);


    sam.setPosition({0.f, 0.f});
    sam.setScale({1.f, 1.f});
    sam.setColor(sf::Color::White);

    // Position Sam inside the window
    sam.setPosition({350.f, 250.f});

    // Make Sam larger for visibility
    // sam.setScale({3.f, 3.f});
    sam.setScale({0.15f, 0.15f});

    auto bounds = sam.getGlobalBounds();

    std::cout << "Sprite position: "
            << bounds.position.x << ", "
            << bounds.position.y << '\n';

    std::cout << "Sprite size: "
            << bounds.size.x << " x "
            << bounds.size.y << '\n';
    sf::Vector2u size = texture.getSize();

    std::cout << "Texture width: " << size.x << '\n';
    std::cout << "Texture height: " << size.y << '\n';
    // Main game loop
    while (window.isOpen())
    {
        // Handle window events
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }


        // Clear the previous frame
        window.clear(sf::Color(30, 30, 40));
        
        window.draw(testRectangle);
        // Draw Sam
        window.draw(sam);

        // Display the new frame
        window.display();
    }

    return 0;
}
