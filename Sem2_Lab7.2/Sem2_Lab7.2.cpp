#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Функция для нахождения расстояния между двумя точками
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Функция для определения принадлежности точки треугольнику
bool belong(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    double d1 = distance(x1, y1, x2, y2);
    double d2 = distance(x2, y2, x3, y3);
    double d3 = distance(x3, y3, x1, y1);
    double d = distance(x1, y1, x, y) + distance(x2, y2, x, y) + distance(x3, y3, x, y);
    return abs((d1 + d2 + d3) - d) < 0.0001; // Проверка на принадлежность
}

// Функция для определения принадлежности точки выпуклому многоугольнику
bool belong(int x, int y, vector<pair<int, int>>& vertices) {
    int n = vertices.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((vertices[i].second > y) != (vertices[j].second > y)) &&
            (x < (vertices[j].first - vertices[i].first) * (y - vertices[i].second) / (vertices[j].second - vertices[i].second) + vertices[i].first)) {
            inside = !inside;
        }
    }
    return inside;
}

int main() {
    setlocale(LC_ALL, "ru");
    // Пример использования функций
    double sideLength = distance(1, 2, 4, 6);
    cout << "Длина стороны: " << sideLength << endl;

    bool inTriangle = belong(1, 1, 4, 1, 2, 5, 3, 2);
    cout << "Принадлежность точки треугольнику: " << (inTriangle ? "Да" : "Нет") << endl;

    vector<pair<int, int>> polygonVertices = { {0, 0}, {4, 0}, {4, 4}, {2, 5}, {1, 3} };
    bool inPolygon = belong(3, 3, polygonVertices);
    cout << "Принадлежность точки многоугольнику: " << (inPolygon ? "Да" : "Нет") << endl;

    return 0;
}