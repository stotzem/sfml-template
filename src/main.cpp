#include "SFML/Graphics.hpp"

int main() {
    sf::RenderWindow window = sf::RenderWindow();
    window.create(sf::VideoMode(1280, 800), "Game");
    window.setVerticalSyncEnabled(true);

    std::vector<sf::CircleShape> shapes;
    shapes.emplace_back(20).setFillColor(sf::Color::Red);
    shapes.emplace_back(20).setFillColor(sf::Color::Blue);
    shapes.emplace_back(20).setFillColor(sf::Color::Green);

    std::map<std::pair<int, int>,  int> field;
    const int rows = 8;
    const int cols = 8;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            field[std::make_pair(x, y)] = rand() % 3 + 1;
        }
    }

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        window.clear(sf::Color(255,255,255,255));
        for (const auto& pair : field) {
            int x = pair.first.first;
            int y = pair.first.second;
            int pieceType = pair.second - 1;
            sf::CircleShape& shape = shapes[pieceType];
            shape.setPosition((float) x * 44 + 20, (float) y * 44 + 20);
            window.draw(shape);
        }
        window.display();
    }
}