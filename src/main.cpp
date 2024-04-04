#include "SFML/Graphics.hpp"

class Main {
  public:

    Main() {
        window.create(sf::VideoMode(1280, 800), "Game");
        window.setVerticalSyncEnabled(true);
        fieldLength = getFieldLength();
        dotSize = fieldLength / (float) rows;

        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < rows; ++x) {
                field[std::make_pair(x, y)] = rand() % 3 + 1;
            }
        }

        shapes.emplace_back(dotSize / 2 - 4).setFillColor(sf::Color::Red);
        shapes.emplace_back(dotSize / 2 - 4).setFillColor(sf::Color::Blue);
        shapes.emplace_back(dotSize / 2 - 4).setFillColor(sf::Color::Green);
    }

    void run() {
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
            window.clear();
            drawField();
            window.display();
        }
    }

  private:

    void drawField() {
        for (const auto& pair : field) {
            int x = pair.first.first;
            int y = pair.first.second;
            int pieceType = pair.second - 1;
            sf::CircleShape& shape = shapes[pieceType];
            shape.setPosition((float) x * dotSize + 20, (float) y * dotSize + 20);
            window.draw(shape);
        }
    }

    float getFieldLength() {
        if (window.getSize().x < window.getSize().y) {
            return (float) window.getSize().x - 40;
        }
        else {
            return (float) window.getSize().y - 40;
        }
    }

    sf::RenderWindow window = sf::RenderWindow();
    std::vector<sf::CircleShape> shapes;
    const int rows = 8;
    float fieldLength;
    float dotSize;
    std::map<std::pair<int, int>,  int> field;
};

int main() {
    Main main;
    main.run();
}