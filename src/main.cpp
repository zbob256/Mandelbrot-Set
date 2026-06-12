#include <SFML/Graphics.hpp>
#include "mandelbrot.hpp"

const int WIDTH = 800;
const int HEIGHT = 600;
const int MAX_ITER = 100;

int main() {
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Mandelbrot Set");
    window.setFramerateLimit(60);

    sf::Image image({WIDTH, HEIGHT}, sf::Color::Black);

    // Loop over each pixel
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            
            // Turn coordinates from window dimensions complex graph in range -2.5 -> 1, and -1 to 1
            double real = static_cast<double>(x) / WIDTH * 3.5 - 2.5;
            double imag = static_cast<double>(y) / HEIGHT * 2 - 1.0;

            int iter = mandelbrot(real, imag, MAX_ITER);

            // Color pixel white if the complex number never escapes, and a shade of gray if not
            if(iter == MAX_ITER) {
                image.setPixel({x, y}, sf::Color(255, 255, 255));
            } else {
                int gray = 255.0 * iter / MAX_ITER;
                image.setPixel({x, y}, sf::Color(gray, gray, gray));
            }
        }
    }

    sf::Texture texture(image);
    sf::Sprite sprite(texture);

    while(window.isOpen()) {
        while(auto event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        window.draw(sprite);

        window.display();
    }
}