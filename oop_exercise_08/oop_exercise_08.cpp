#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <future> 
#include <chrono>
#include <map>
#include "figure.h"

using namespace std;

void help() {
	cout << "you can use:\n";
	cout << "'add' for adding square(S), rectangle(R) or trape(T)\n";
	cout << "'exit' for exit\n";
}

void wait(future<int>& fut) {

    int f = fut.get();
    if (f) {
        cout << "\n...All data processed successfully...\n\n";
    } 
}

int main (int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "invalid input(enter exec file + buffer size)\n");
        exit(0);
    }

    using Point = Pair<double,double>;
    int size = atoi(argv[1]);
    vector<IFigure*> buf;
    Publisher pub(buf, size);
    string sout = "stdout";
    string fout = "output";
    Subscriber sub2(sout);
    Subscriber sub1(fout);
    pub.Subscribe(sub1);
    pub.Subscribe(sub2);
    int id = 1;
    Point a, b, c, d;
    char ftype;
	string str;    
	IFigure* fig;
    help();
    while (cin >> str) {
        future<int> fut;
        if (str == "add") {
        	cin >> ftype;
			cin >> a >> b >> c >> d;
			if (ftype == 'S') {
                if(isSquare(a,b,c,d)) {
				    fig = new Square(id, a, b, c, d);
                    id++;
                    printf("figure added\n");
                } else printf("it`s not a square\n");
			} else if (ftype == 'R') {
                if (isRectangle(a,b,c,d)){
				    fig = new Rectangle(id, a, b, c, d);
                    id++;
                    printf("figure added\n");
                } else printf("it`s not a rectangle\n");
			} else if (ftype == 'T') {
                if (isTrape(a,b,c,d)) {
				    fig = new Trape(id, a, b, c, d);
                    id++;
                    printf("figure added\n");
                } else printf("it`s not a trape\n");
       		}
                fut = async(&Publisher::Add,&pub,fig);
                wait(fut);
        } else if (str == "help") {
        	help();
        } else if (str == "exit") {
            exit(0);
        }
                         
    }
    return 0;
}