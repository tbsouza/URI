#include<bits/stdc++.h>
using namespace std;

const double EPS=1e-9;
inline int cmp(double x, double y=0, double tol=EPS){
    return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

struct ponto {

    double x, y;

    ponto(){}
    ponto(double x, double y):x(x), y(y){}
    ponto (ponto a, ponto b){ // vec(a,b)
        x = (b.x-a.x); y = (b.y-a.y);
    }

    ponto operator +(ponto q){ return ponto(x+q.x, y+q.y); }
    ponto operator -(ponto q){ return ponto(x-q.x, y-q.y); }
    ponto operator *(double t){ return ponto(x*t, y*t); }
    ponto operator /(double t){ return ponto(x/t, y/t); }

    int cmp(ponto q) const{
        if(int t = ::cmp(x, q.x)) return t;
        return ::cmp(y,q.y);
    }

    bool operator == (ponto q) const { return cmp(q) == 0; };
    bool operator != (ponto q) const { return cmp(q) != 0; };
    bool operator < (ponto q) const { return cmp(q) < 0; };

    double operator *(ponto q){ return x*q.x + y*q.y; }
    double operator %(ponto q){ return x*q.y - y*q.x; }
};
typedef ponto vec;

double norma(vec u) { return sqrt(u*u); }

int ccw(ponto p, ponto q, ponto r){
    return cmp( vec(p,q) % vec(p,r) );
}

vec projecao(vec a, vec b){
    return b * ((a*b) / (b*b));
}

bool entre(ponto r, ponto p, ponto s){
    return cmp(vec(p,s)%vec(p,r))==0 &&
    cmp(vec(p,r)*vec(p,s)) <= 0;
}

// Distancia entre point r e segmento pq
double PTSeg(ponto p, ponto q, ponto r) {
    ponto A = r - q, B = r - p, C = q - p;

    double a = A * A, b = B * B, c = C * C;

    if (cmp(b, a + c) >= 0 ) return sqrt(a);
    else if (cmp(a, b + c) >= 0 ) return sqrt(b);
    else return fabs(A % B) / sqrt(c);
}

double L, H;
int N;
vector< pair<vec,vec> > aleta;
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f

int main(){

    double Yi, Xf, Yf, m, a, b;

    while( scanf("%d", &N) !=EOF ){

        scanf( "%lf%lf", &L, &H );

        aleta.clear();
        m=double(INF);

        for( int i=0; i<N; ++i ){

            scanf( "%lf%lf%lf", &Yi, &Xf, &Yf );

            if( i%2==0 )
                aleta.pb( mp( vec(0,Yi), vec(Xf,Yf) ) );
            else
                aleta.pb( mp( vec(L,Yi), vec(Xf,Yf) ) );
        }

        for( int i=0; i<(N-1); ++i ){

            vec pf = aleta[i].second;
            vec pa = aleta[i+1].first;
            vec pb = aleta[i+1].second;

            a = PTSeg(pa, pb, pf);

            if( i%2==0 ) b = L - pf.x;
            else         b = pf.x;

            if( cmp(a, b, EPS)==-1 ){
                if( cmp(a, m, EPS)==-1 ) m=a;
            }else{
                if( cmp(b, m, EPS)==-1 ) m=b;
            }

        }

        vec pf = aleta[N-1].second;

        if( (N-1)%2==0 ) b = L - pf.x;
        else             b = pf.x;

        if( cmp(b, m, EPS)==-1 ) m=b;

        printf( "%.2lf\n", m );
    }

    return 0;
}
