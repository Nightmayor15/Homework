//#include "C:\Users\user\Desktop\С++\Homework\sem7\Vectors.h"
#include "Vectors (copy).h"
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

/// @brief Преобразование графа из файла в список смежности
/// @param filename Имя файла с графом (1-ая строка - количество вершин, следующие строки - концы ребра и его вес)
/// @return Список с графом
Vector<Vector<double>> read_graph(std::string filename)
{
    
  /*
  {
        double ** gggraph;
        int n = 8;
        gggraph = (double**) malloc(n*n*sizeof(Vector<int>) + n*sizeof(int));
        gggraph[0] = (double*)gggraph + n;
        for (int i = 1; i < n; ++i){
            gggraph[i] = gggraph[i-1] + n;
        }
        free(gggraph);
    }
    
    */  
    std::ifstream graph_file(filename); //Файл с графом
    std::string line; //Строки в файле (при i > 1 - веса графа)
    int i = 1; //Счётчик строк
    Vector<Vector<double>> graph; //Список смежности
    while (std::getline(graph_file, line))
    {
        if (line == "" || line == " ") {std::cout << "END"; break;}
        if (i == 1)
        {
            int n = stoi(line); //Количество вершин
            for (int t = 0; t < n; t++) //Заполняем список смежности бесконечностями
            {
                Vector<double> a; //Список соседей
                for(int p = 0; p < n; p++)
                {
                    a.append(std::numeric_limits<double>::infinity());
                }
                graph.append(a);
            }
        }
        else
        {
            std::string k; //Значение вершины или веса
            std::stringstream l(line); //Преобразование строки в поток
            int j = 1; //Счётчик символов в строке
            int a, b; //Вершины ребра
            double w; //Вес ребра
            while(getline(l, k, ' ') && j < 4)
            {
                if (j == 1) a = stoi(k);
                else if (j == 2) b = stoi(k);
                else w = stod(k);
                j++;
            }
            graph[a][b] = w;
            graph[b][a] = w;
        }
        i++;
    }
    graph_file.close();
    for (auto i: graph)
    {
        for (int j = 0; j < graph.len(); j++)
        {
            std::cout << i[j] << " ";
        }
        std::cout << "\n";
    }
    return graph;
}

/// @brief Алгоритм Дейкстры
/// @param adj_list Список смежности графа
/// @param start Начальная вершина
/// @return Список с дистанциями
Vector<double> dijkstra(Vector<Vector<double>> adj_list, int start)
{
    Vector<Vector<double>> queue; //Очередь
    Vector<double> dist; //Список дистанций
    for (auto t: adj_list)
    {
        dist.append(std::numeric_limits<double>::infinity());
    }
    Vector<int> used; //Список пройденных вершин
    dist[start] = 0;
    Vector<double> t; //0 - Дистанция, 1 - Вершина, 2 - Предыдущая вершина
    t.append(0); t.append(start);
    queue.append(t);
    int i = 0; //Индекс для очереди
    while (queue.len() > i)
    {
        double d = queue[i][0]; //Дистанция до нынешней вершины
        int v = queue[i][1]; //Нынешняя вершина
        i++;
        int indicator = 0; //Индикатор на присутствие в used
        for (auto u: used)
        {
            if (u == v) indicator = 1;
        }
        if (indicator == 1) continue;       
        else
        {
            used.append(v);
            for (int j = 0; j < adj_list.len(); j++)
            {
                if (dist[j] > d + adj_list[v][j])
                {
                    dist[j] = d + adj_list[v][j];
                    Vector<double> t;
                    t.append(dist[j]); t.append(j);
                    queue.append(t);
                    double min = 800000;
                    for (int ind = i; ind < queue.len(); ind++)
                    {
                        if (queue[ind][0] < min) min = queue[ind][0];
                    }
                    for (int ind = 0; ind < queue.len(); ind++)
                    {
                        if (min == queue[ind][0])
                        {
                            Vector<double> tmp;
                            tmp = queue[ind];
                            queue[ind] = queue[i];
                            queue[i] = tmp;
                            break;
                        } 
                    }
                }
            }
        }
    }
    return dist;
};

/// @brief Нахождение кратчайшего пути (с конца в начало)
/// @param graph Список смежности графа
/// @param dist Список с дистанциями
/// @param goal Начальная вершина
/// @param vertex Текущая вершина
/// @param route Запись итога
/// @return Список с путём
Vector<int> path(Vector<Vector<double>> graph, Vector<double> dist, int goal, int vertex, Vector<int> route)
{
    route.append(vertex);
    if (vertex == goal) return route;
    for (int i = 0; i < dist.len(); i++)
    {
        if (dist[vertex] - dist[i] == graph[vertex][i])
        {
            route = path(graph, dist, goal, i, route);
            return route;
        }

    }
}

int main()
{
    Vector<Vector<double>> graph = read_graph("Graph.txt");
    Vector<double> map = dijkstra(graph, 0);
    std::cout << "\n\n";
    for (auto i: map) std::cout << i << " ";
    std::cout << "\n";
    if (map[2] != std::numeric_limits<double>::infinity())
    {
        Vector<int> route;
        route = path(graph, map, 0, 2, route);
        for (auto i : route)
        {
            if (route[-1] == i) std::cout << i << "\n";
            else std::cout << i << " <- " ;
        }
    }
    else std::cout << "Impossible to find a way";
    return 0;
}

