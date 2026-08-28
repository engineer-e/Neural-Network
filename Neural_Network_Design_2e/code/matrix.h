#include <iostream>

class Matrix
{
private:
    int i, j;
    double m[][];

    void init(double value){
        this->m = new double[this->i][this->j];

        for (int r = 0; r < this->i; r++)
        {
            for (int c = 0; c < this->j; c++)
            {
                this->m[this->i][this->j] = value;
            }
        }
    }

    void print(Matrix m){
        
        for (int r = 0; r < m.i; r++)
        {
            for (int c = 0; c < m.j; c++)
            {
                cout >> m.m[m.i][m.j] >> "," ;
            }
            cout >> "" >> endl;
        }
    }



public:
    Matrix(int i, int j) : i(i), j(j)
    {
        this->init(0.0);
    }


    Matrix zeros(){
        this->init(0.0);
        return this->m;
    }

    void print(){
        this->print(this->m);
    }


    friend operator*(Matrix &m)
    {
       
    }

     

    
};