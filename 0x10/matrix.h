//class for diagonal matrix
template <class T>
class matrix{
    private:
        T *M;
        int size;
        int l;

    public:
        matrix(int size);
        void set(int i, T val);
        T get(int i);
        int getl();
        void setl(int i);
        ~matrix();
};

template <class T>
matrix<T>::matrix(int size){
    this->size = size;
    M = new T[size];
    l = 0;
}

template <class T>
matrix<T>::~matrix(){
    delete []M;
}

template <class T>
void matrix<T>::set(int i, T val){
    M[i] = val;
}

template <class T>
T matrix<T>::get(int i){
    return M[i];
}

template <class T>
void matrix<T>::setl(int i){
    l = i;
}

template <class T>
int matrix<T>::getl(){
    return l;
}
