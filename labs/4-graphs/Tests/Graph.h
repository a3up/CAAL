/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>

using namespace std;

template<class T>
class Edge;

template<class T>
class Graph;

template<class T>
class Vertex;


/****************** Provided structures  ********************/

template<class T>
class Vertex {
    T info;                // contents
    vector<Edge<T> > adj;  // list of outgoing edges
    bool visited;          // auxiliary field used by dfs and bfs
    int indegree;          // auxiliary field used by topsort
    bool processing;       // auxiliary field used by isDAG

    void addEdge(Vertex<T> *dest, double w);

    bool removeEdgeTo(Vertex<T> *d);

public:
    explicit Vertex(T in);

    friend class Graph<T>;
};

template<class T>
class Edge {
    Vertex<T> *dest;      // destination vertex
    double weight;         // edge weight
public:
    Edge(Vertex<T> *d, double w);

    friend class Graph<T>;

    friend class Vertex<T>;
};

template<class T>
class Graph {
    vector<Vertex<T> *> vertexSet;    // vertex set

    void dfsVisit(Vertex<T> *v, vector<T> &res) const;

    Vertex<T> *findVertex(const T &in) const;

    bool dfsIsDAG(Vertex<T> *v) const;

public:
    int getNumVertex() const;

    bool addVertex(const T &in);

    bool removeVertex(const T &in);

    bool addEdge(const T &sourc, const T &dest, double w);

    bool removeEdge(const T &sourc, const T &dest);

    vector<T> dfs() const;

    vector<T> bfs(const T &source) const;

    vector<T> topsort() const;

    int maxNewChildren(const T &source, T &inf) const;

    bool isDAG() const;
};

/****************** Provided constructors and functions ********************/

template<class T>
Vertex<T>::Vertex(T in): info(in) {}

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


template<class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template<class T>
Vertex<T> *Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

/****************** 1a) addVertex ********************/

/*
 *  Adds a vertex with a given content/info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template<class T>
bool Graph<T>::addVertex(const T &in) {
    if (findVertex(in) != NULL)
        return false;
    auto toAdd = new Vertex<T>(in);
    this->vertexSet.push_back(toAdd);
    return true;
}

/****************** 1b) addEdge ********************/

/*
 * Adds an edge to a graph (this), given the contents of the source (sourc) and
 * destination (dest) vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    auto source = findVertex(sourc);
    auto destination = findVertex(dest);
    if (source == NULL || destination == NULL)
        return false;
    source->addEdge(destination, w);
    return true;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template<class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    auto toAdd = Edge<T>(d, w);
    this->adj.push_back(toAdd);
}


/****************** 1c) removeEdge ********************/

/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
template<class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    auto source = findVertex(sourc);
    auto destination = findVertex(dest);
    if (source == NULL || destination == NULL)
        return false;
    return source->removeEdgeTo(destination);
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
template<class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    for (auto a = adj.begin(); a != adj.end(); ++a)
        if (a->dest == d) {
            adj.erase(a);
            return true;
        }
    return false;
}


/****************** 1d) removeVertex ********************/

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
template<class T>
bool Graph<T>::removeVertex(const T &in) {
    auto toRemove = findVertex(in);
    if (toRemove == NULL)
        return false;
    for (auto iter = vertexSet.begin(); iter != vertexSet.end(); ++iter)
        if ((*iter)->info == in) {
            vertexSet.erase(iter);
            break;
        }
    for (const auto &vertex : vertexSet)
        vertex->removeEdgeTo(toRemove);
    return true;
}


/****************** 2a) dfs ********************/

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template<class T>
vector<T> Graph<T>::dfs() const {
    vector<T> res;
    for (auto &vertex : this->vertexSet)
        vertex->visited = false;
    for (auto &vertex : this->vertexSet)
        if (!vertex->visited)
            dfsVisit(vertex, res);
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template<class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> &res) const {
    v->visited = true;
    res.push_back(v->info);
    for (auto &adjEdge : v->adj) {
        auto adjVertex = adjEdge.dest;
        if (!adjVertex->visited)
            dfsVisit(adjVertex, res);
    }
}

/****************** 2b) bfs ********************/

/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template<class T>
vector<T> Graph<T>::bfs(const T &source) const {
    // HINT: Use the flag "visited" to mark newly discovered vertices .
    // HINT: Use the "queue<>" class to temporarily store the vertices.
    vector<T> res;
    auto s = findVertex(source);
    if (s == NULL)
        return res;
    queue<Vertex<T> *> queue;
    for (auto v : vertexSet)
        v->visited = false;
    queue.push(s);
    s->visited = true;
    while (!queue.empty()) {
        auto vertex = queue.front();
        queue.pop();
        res.push_back(vertex->info);
        for (auto &edge : vertex->adj) {
            auto v = edge.dest;
            if (!v->visited) {
                queue.push(v);
                v->visited = true;
            }
        }
    }
    return res;
}

/****************** 2c) toposort ********************/

/*
 * Performs a topological sorting of the vertices of a graph (this).
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 * Follows the algorithm described in theoretical classes.
 */

template<class T>
vector<T> Graph<T>::topsort() const {
    for (auto &v : this->vertexSet)
        v->indegree = 0;
    for (auto &v : this->vertexSet)
        for (auto &e : v->adj) {
            auto w = e.dest;
            w->indegree++;
        }
    queue<Vertex<T> *> c;
    for (auto &v : this->vertexSet)
        if (v->indegree == 0)
            c.push(v);
    vector<T> res;
    while (!c.empty()) {
        auto v = c.front();
        c.pop();
        res.push_back(v->info);
        for (auto &e : v->adj) {
            auto w = e.dest;
            if (--w->indegree == 0)
                c.push(w);
        }
    }
    if (res.size() != this->vertexSet.size())
        res.clear();
    return res;
}

/****************** 3a) maxNewChildren (HOME WORK)  ********************/

/*
 * Performs a breadth-first search in a graph (this), starting
 * from the vertex with the given source contents (source).
 * During the search, determines the vertex that has a maximum number
 * of new children (adjacent not previously visited), and returns the
 * contents of that vertex (inf) and the number of new children (return value).
 */

template<class T>
int Graph<T>::maxNewChildren(const T &source, T &inf) const {
    auto s = findVertex(source);
    if (s == NULL)
        return 0;
    queue<Vertex<T> *> queue;
    for (auto v : vertexSet)
        v->visited = false;
    queue.push(s);
    s->visited = true;
    int res = -1;
    while (!queue.empty()) {
        int count = 0;
        auto vertex = queue.front();
        queue.pop();
        for (auto &edge : vertex->adj) {
            auto v = edge.dest;
            if (!v->visited) {
                queue.push(v);
                v->visited = true;
                count++;
            }
        }
        if (count > res) {
            res = count;
            inf = vertex->info;
        }
    }
    return res;
}

/****************** 3b) isDAG   (HOME WORK)  ********************/

/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the the stack of recursive calls (see theoretical classes).
 * Returns true if the graph is acyclic, and false otherwise.
 */

template<class T>
bool Graph<T>::isDAG() const {
    // HINT: use the auxiliary field "processing" to mark the vertices in the stack.
    for (auto &vertex : this->vertexSet) {
        vertex->visited = false;
        vertex->processing = false;
    }
    for (auto &vertex : this->vertexSet)
        if (!vertex->visited)
            if (!dfsIsDAG(vertex))
                return false;
    return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template<class T>
bool Graph<T>::dfsIsDAG(Vertex<T> *v) const {
    v->visited = true;
    v->processing = true;
    for (auto &adjEdge : v->adj) {
        auto adjVertex = adjEdge.dest;
        if (adjVertex->processing)
            return false;
        if (!adjVertex->visited)
            if (!dfsIsDAG(adjVertex))
                return false;
    }
    v->processing = false;
    return true;
}

#endif /* GRAPH_H_ */
