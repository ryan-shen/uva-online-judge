#include<iostream>
#include<cstdio>
using namespace std;

void print_number( long long n ){
    if( n == 0 ) return;
    
    if( n/10000000 ){
        print_number( n/10000000 );
        printf( " kuti" );
        n %= 10000000;
    }
    
    if( n/100000 ){
        print_number( n/100000 );
        printf( " lakh" );
        n %= 100000;
    }
    
    if( n/1000 ){
        print_number( n/1000 );
        printf( " hajar" );
        n %= 1000;
    }
    
    if( n/100 ){
        print_number( n/100 );
        printf( " shata" );
        n %= 100;
    }
    
    if( n ) printf( " %lld", n );
}

int main(){
    long long n;
    int test = 1;
    while( scanf( "%lld", &n ) != EOF ){
        printf( "%4d.", test );
        if( n ) print_number( n );
        else printf( " 0" );
        printf( "\n" );
        test++;
    }
    return 0;
}
