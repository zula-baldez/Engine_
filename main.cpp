#include <SFML/Graphics.hpp>
#include "Figure.h"
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

void ball();

double toRadian(double a);

void naklon();

using namespace sf;

int main() {
   /* std::vector<Figure> figures;
    CircleShape circleShape(100.f);
    Figure figure(circleShape, false, 10);
    figure.speedx = 0.1;
    figure.tyazest = Strenght(toRadian(90), 9.81);
    figures.push_back(figure);
    double deltat = 0.01;
    RectangleShape poddon(Vector2f(1920, 50));
    Figure figure1(poddon, true, 123456789);
    figure1.x = 0;
    figure1.y = 1030;
    figures.push_back(figure1);
    RenderWindow window(VideoMode(1920, 1080), "zxc", Style::Fullscreen);

    for (double i = 1; i <= 100000000; i++) {
        window.clear();
        for (auto& j: figures) {
            double x = j.reactionOfOpora.value * cos(j.reactionOfOpora.angle) +
                       j.trenie.value * cos(j.trenie.angle) +
                       j.tyazest.value * cos(j.tyazest.angle);

            double y = j.reactionOfOpora.value * sin(j.reactionOfOpora.angle) +
                       j.trenie.value * sin(j.trenie.angle) +
                       j.tyazest.value * sin(j.tyazest.angle);

            double ax = x / j.mass;
            double ay = y / j.mass;

            j.x = j.x+ j.speedx * deltat + ax * deltat * deltat / 2;
            j.y += j.speedy * deltat + ay * deltat * deltat / 2;
            j.speedx += ax * deltat;
            j.speedy += ay * deltat;
            std::cout<<j.speedy<<std::endl;
            if(j.y>=1030-200 && j.isConcrete == false) {





                j.reactionOfOpora = Strenght(toRadian(-90), 0.001*abs(1030-j.y)*abs(1030-j.y)*abs(1030-j.y));

            }
            else {
                j.reactionOfOpora = Strenght(0, 0);
            }
            j.shape->setPosition(j.x, j.y);

            window.draw(*(j.shape));
        }
        window.display();
    }*/
   ball();
}

double toRadian(double a) {
    return a/(180/3.1415);
}


void naklon() {
    RenderWindow window(VideoMode(1000, 1000), "zxc", Style::Fullscreen);
    // создаём пустую фигуру
    sf::ConvexShape convex;

    double alpha = atan(300.0 / 500.0);

    /*brusok.setPointCount(4);
    brusok.setPoint(0, sf::Vector2f(30*sin(alpha), 700-30*cos(alpha))); //LH
    brusok.setPoint(2, sf::Vector2f(100*cos(alpha)+30*sin(alpha), 700-30*cos(alpha)+100*sin(alpha))); //RH
    brusok.setPoint(1, sf::Vector2f(0, 700));
    brusok.setPoint(3, sf::Vector2f(100*cos(alpha), 700+100*sin(alpha)));*/

    RectangleShape rectangle(Vector2f(100, 30));
    rectangle.setPosition(30 * sin(alpha), 700 - 30 * cos(alpha));
    rectangle.setFillColor(Color::Magenta);

    rectangle.rotate(alpha * 180 / 3.1415926);
// изменяем размер на 5 вершин
    convex.setPointCount(3);

// определяем вершины
    convex.setPoint(0, sf::Vector2f(0, 700));
    convex.setPoint(1, sf::Vector2f(0, 1000));
    convex.setPoint(2, sf::Vector2f(500, 1000));
    double v = 0;
    double t = 0;
    double mu = 0.55;
    double g = 9.81;
    double a = g * sin(alpha) - g * cos(alpha) * mu;
    int s = 0;
    bool down = 1;
    for (;;) {
        t += 0.1;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));

        if (a >= 0 && down == 1) {
            s = a * t * t / 2;
            rectangle.move(s * cos(alpha), s * sin(alpha));
        }
        if (rectangle.getPosition().y + 30 * cos(alpha) + 100 * sin(alpha) >= 1000) {
            std::cout << rectangle.getPosition().y;
            down = 0;

        }
        window.clear();
        window.draw(convex);
        window.draw(rectangle);

        window.display();
    }

}

void ball() {
    RenderWindow window(VideoMode(1000, 1000), "HAHAHHAHAHAHA", Style::Fullscreen);
    CircleShape shape(100.f);
    shape.setPosition(500, -100);
    shape.setFillColor(Color::Red);
    RectangleShape rectangle(Vector2f(1000, 399));
    rectangle.setPosition(0, 700);
    double v = 0;
    double y = 0; //относительно -100, вниз
    double y0 = 0;
    double t = 0;
    double v0 = 0;
    bool down = true;
    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        t += 0.2;
        std::cout << shape.getPosition().y << std::endl;
        if (down) {
            if (shape.getPosition().y <= 500) {
                y = y0 + 9.81 * t * t / 2;
                v = 9.81 * t;
            } else {
                v = 0;
            }
        } else {
            if (v > 0) {
                y = y0 - v0 * t + 9.81 * t * t / 2;
                v = v0 - 9.81 * t;
            }
        }

        shape.setPosition(500, y);
        if (shape.getPosition().y >= 500 && down) {

            y0 = y;
            down = false;
            v0 = v * 0.8;
            t = 0;

        }
        if (v <= 0 && !down) {
            y0 = y;
            down = true;
            v0 = 0;
            t = 0;
            v = 0;
        }
        window.clear();
        window.draw(shape);
        window.draw(rectangle);
        window.display();
    }
}
