#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <initializer_list>

template <typename T>
class Matrix{
private:

    std::vector<std::vector<T> > m_mat ;
    
public:
    Matrix(const std::initializer_list<T>& _il){ 
        auto it = _il.begin();
        m_mat.resize(*it);
        ++it;
        for(unsigned int i=0;i<m_mat.size();++i){
            m_mat[i].resize(*it);
        }
        ++it;
        for(unsigned int i=0;i<m_mat.size();++i){
            for(unsigned int j=0;j<m_mat[i].size();++j){
                m_mat[i][j]=*it;
                if(it==_il.end()){
                   m_mat[i][j]=0;
                }else ++it;
            }
        }
    };
    Matrix(uint _rows, uint _cols, const std::initializer_list<T>& _il) {
        m_mat.resize(_rows);
        for(unsigned int i=0;i<m_mat.size();++i){
            m_mat[i].resize(_cols);
        }
        auto it = _il.begin();
        for(unsigned int i=0;i<m_mat.size();++i){
            for(unsigned int j=0;j<m_mat[i].size();++j){
                m_mat[i][j]=*it;
                if(it==_il.end()){
                   m_mat[i][j]=0;
                }else ++it;
            }
        }
    };
    Matrix(){
        
    };
    Matrix(unsigned int _rows, unsigned int _cols){
        m_mat.resize(_rows);
        for(unsigned int i=0;i<_rows;++i){
            m_mat.at(i).resize(_cols);
        }
    };
    Matrix(Matrix<T> const & _m){
        std::vector<std::vector<T>> const & mat = _m.getMat();
        m_mat.resize(mat.size());
        for(unsigned int i=0;i<mat.size();++i){
            m_mat[i].resize(mat[i].size());
            for(unsigned int j=0;j<mat.at(i).size();++j){
                m_mat[i][j] = mat[i][j];
            }
        }
    };
    Matrix(std::vector<std::vector<T>> const & _vv){
        m_mat.resize(_vv.size());
        for(unsigned int i=0;i<_vv.size();++i){
            m_mat[i].resize(_vv[i].size());
            for(unsigned int j=0;j<_vv.at(i).size();++j){
                m_mat[i][j] = _vv[i][j];
            }
        }
    };
    Matrix<T> & operator=(const Matrix<T> & _m){
        std::vector<std::vector<T>> const & mat = _m.getMat();
        m_mat.resize(mat.size());
        for(unsigned int i=0;i<mat.size();++i){
            m_mat[i].resize(mat[i].size());
            for(unsigned int j=0;j<mat.at(i).size();++j){
                m_mat[i][j] = mat[i][j];
            }
        }
        return *this;
    };
    T sum(){
        T sum = 0;
        for(auto row : m_mat){
            for(auto val : row){
                sum+=val;
            }
        }
        return sum;
    };
    Matrix<T> const & operator*(Matrix<T> const & _m){                                                                              // [3,2] * [2,4] = [3,4]
        std::vector<std::vector<T>> result(m_mat.size());
        std::vector<std::vector<T>> const & m2 = _m.getMat();
        for(unsigned int i=0;i<result.size();++i){
            result[i].resize(m2[0].size());
            for(unsigned int j=0;j<m2[0].size();++j){
                T acc = 0;
                for(unsigned int k=0;k<m_mat[i].size();++k){
                    acc+=m_mat[i][k] * m2[k][j];
                }
                result[i][j] = acc;
            }
        }
        Matrix<T> * mr = new Matrix<int>(result);
        return *mr;
    };
    void invert(){
        std::vector<std::vector<T>> newv(m_mat[0].size());
        for(unsigned int i=0;i<m_mat.size();++i){
            for(unsigned int j=0;j<m_mat[i].size();++j){
                newv[j].resize(i+1);
                newv[j][i]=m_mat[i][j];
            }
        }
        m_mat = newv;
    };
    std::vector<std::vector <T> >  const & getMat() const{
        return m_mat;
    };
    void show() const{
        for(unsigned int i=0;i<m_mat.size();++i){
            for(unsigned int j=0;j<m_mat[i].size();++j){
                std::cout << m_mat[i][j] << " " ;
            }
            std::cout << std::endl;
        }
        
    }
};
#endif
