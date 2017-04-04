#include <cstdio>
#include <iostream>
#include <queue>

#define MAX 5000
#define INF 999999999

using namespace std;
struct node {
	int node_to;	//to
	int node_weight; //weight || cost

					 //default constructor
	node(int elements1, int elements2) : node_to(elements1), node_weight(elements2) {};
};

//overload the cmp class
struct cmp {
	bool operator()(node n1, node n2)
	{
		return n1.node_weight < n2.node_weight;
	}
};

int num_of_nodes, num_of_edges, start_point_size;
vector<node> adj[MAX];
vector<int> answer(MAX, INF);

//vector<int> start_point;
int start_point[50000];
int dist[MAX];
int prev_node[MAX];
void dijkstra(int startVertexNum)
{
	//priority que will pop the data as CMP declaed
	priority_queue<node, vector<node>, cmp> pq;
	for (int i = 1; i <= num_of_nodes; i++)
	{
		pq.push(node(i, INF));	//insert the data
	}
	dist[startVertexNum] = 0;	//start point's distance always be 0
	answer[startVertexNum] = 0;
	prev_node[startVertexNum] = startVertexNum;
	pq.push(node(startVertexNum, dist[startVertexNum]));
	while (!pq.empty())
	{
		int nextvisit = pq.top().node_to;
		int Cost_to_next = pq.top().node_weight;
		pq.pop();

		//if dist[next] is small than cost,
		//a better route is available
		if (dist[nextvisit] < Cost_to_next)
			continue;

		//check the other nodes at nextvisit node;
		for (int i = 0; i < adj[nextvisit].size(); i++)
		{
			node another_node = adj[nextvisit][i];
			if (dist[another_node.node_to] > dist[nextvisit] + another_node.node_weight)
			{
				dist[another_node.node_to] = dist[nextvisit] + another_node.node_weight;
				pq.push(node(another_node.node_to, dist[another_node.node_to]));

				if (prev_node[another_node.node_to] > startVertexNum)
					prev_node[another_node.node_to] = startVertexNum;
				if (dist[another_node.node_to] < answer[another_node.node_to])
				{
					answer[another_node.node_to] = dist[another_node.node_to];	//distance renewal
				}
			}
		}
	}
}
void init_distance()
{
	for (int i = 1; i <= num_of_nodes; i++)
		dist[i] = INF;
}
int from, to, cost;

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	//setbuf(stdout, NULL);
	int test_index = 1;
	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		//scanf("%d %d %d", &num_of_nodes, &num_of_edges, &start_point_size);
		scanf("%d", &num_of_nodes);
		scanf("%d", &num_of_edges);
		scanf("%d", &start_point_size);

		//receive all edges data;
		for (int i = 0; i < num_of_edges; i++)
		{
			scanf("%d %d %d", &from, &to, &cost);
			//link each nodes (cause It would be a bi-direction graph
			adj[from].push_back(node(to, cost));
			adj[to].push_back(node(from, cost));
		}

		//start_point.resize(start_point_size);

		for (int i = 0; i < start_point_size; i++)
		{
			scanf("%d", &start_point[i]);
		}
		//SET node num INF;
		for (int i = 1; i <= num_of_nodes; i++)
			prev_node[i] = INF;

		for (int i = 0; i < start_point_size; i++)
		{
			//init ex_distance
			init_distance();
			//start searching
			dijkstra(start_point[i]);
		}
		int ans1 = 0, ans2 = 0;
		//check the data 
		for (int i = 1; i <= num_of_nodes; i++) {
			//printf("dist[%d] = %d \t", i, answer[i]);
			//printf("prev[%d] = %d\n", i, prev_node[i]);
			//ans1 += answer[i];
			//ans2 += prev_node[i];
		}
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n%d\n", ans1, ans2);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
