#include<iostream>
#include<chrono>          // 在编译时使用 g++ test.cpp -std=c++11 -O3 加速指令进行编译可以提高3倍的速度
#include<immintrin.h> // 使用simd技术时，需要使用该头文件, 并且编译时要加上 -mavx2参数，才能正确编译，如：g++ .\hello.cpp -std=c++11 -O3 -mavx2
#include<omp.h> //使用openMp技术时需要该头文件, 并且编译时要加上 -fopenmp参数
using namespace std;

void dotmult1(float *a, float *b, float &result,size_t n);  
void dotmult2(float *a, float *b, float &result,size_t n);
void simd_avx2(float *a, float *b, float &result,size_t n); 
void openmp(float *a, float *b, float &result,size_t n);
int main(){
    std::chrono::steady_clock::time_point start,end; // 也可以用auto类型
    size_t n = 2000000;
    float *a = new float[n]();// 初始化为0
    float *b = new float[n]();
    float result = 0.0f;
    a[1] = 2.3f;
    b[1] = 2.0f;
    a[n-1] = 2.0f;
    b[n-1] = 2.3f;
    dotmult1(a,b,result,n);//预热数据，先把数据使用一次，这样后续不会因为先后调用数据，而产生cash命中率不同导致的时间差

    start = std::chrono::steady_clock::now();
    dotmult1(a,b,result,n);
    end = std::chrono::steady_clock::now();
    cout<<"in dotmult1\n";
    cout<<"result = "<<result<<endl;
    cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<"ms"<<endl;

    start = std::chrono::steady_clock::now();
    dotmult2(a,b,result,n);
    end = std::chrono::steady_clock::now();
    cout<<"in dotmult2\n";
    cout<<"result = "<<result<<endl;
    cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<"ms"<<endl;

    start = std::chrono::steady_clock::now();
    simd_avx2(a,b,result,n);
    end = std::chrono::steady_clock::now();
    cout<<"in simd_avx2\n";
    cout<<"result = "<<result<<endl;
    cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<"ms"<<endl;
    
    start = std::chrono::steady_clock::now();
    openmp(a,b,result,n);
    end = std::chrono::steady_clock::now();
    cout<<"in openmp\n";
    cout<<"result = "<<result<<endl;
    cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<"ms"<<endl;

    delete []a;
    delete []b;
    return 0;
}   
void dotmult1(float *a, float *b, float &result,size_t n){
    result = 0.0f;
    for(size_t i=0;i<n;i++) result += a[i]*b[i];
}
void dotmult2(float *a, float *b, float &result,size_t n){
    result = 0.0f;
    for(size_t i=0;i<n;i+=8){
        result += a[i]*b[i];
        result += a[i+1]*b[i+1];
        result += a[i+2]*b[i+2];
        result += a[i+3]*b[i+3];
        result += a[i+4]*b[i+4];
        result += a[i+5]*b[i+5];
        result += a[i+6]*b[i+6];
        result += a[i+7]*b[i+7];

    }
}
void simd_avx2(float *a, float *b, float &result,size_t n){
    float temp[8] = {0};
    __m256 A,B;                     // A,B为256为的寄存器
    __m256 C = _mm256_setzero_ps(); // 将C置零
    for(size_t i=0;i<n;i+=8){
        A = _mm256_load_ps(a+i); // 从a数组中取8个浮点数交给a
        B = _mm256_load_ps(b+i);
        C = _mm256_add_ps(C,_mm256_mul_ps(A,B)); // 将A B相乘的结果加给C
    }
    _mm256_store_ps(temp,C); // 将C中的结果放到temp数组中
    result = 0;
    for(size_t i=0;i<8;i++) result+=temp[i];
}
void openmp(float *a, float *b, float &result,size_t n){
    float temp[8] = {0};
    __m256 A,B;                     // A,B为256为的寄存器
    __m256 C = _mm256_setzero_ps(); // 将C置零
    #pragma omp parallel for
    for(size_t i=0;i<n;i+=8){
        A = _mm256_load_ps(a+i); // 从a数组中取8个浮点数交给a
        B = _mm256_load_ps(b+i);
        C = _mm256_add_ps(C,_mm256_mul_ps(A,B)); // 将A B相乘的结果加给C
    }
    _mm256_store_ps(temp,C); // 将C中的结果放到temp数组中
    result = 0;
    for(size_t i=0;i<8;i++) result+=temp[i];
}
