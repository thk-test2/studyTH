#include <iostream>

int main() {

    int NA, MA;
    int NB, MB;

    std::cin >> NA >> MA;
    int mat_a[NA][MA] = {0,};
    for (int i=0; i< NA; i++) {
        for (int j=0; j< MA; j++) {
            std::cin >> mat_a[i][j];
        }
    }

    std::cin >> NB >> MB;
    int mat_b[NB][MB] = {0,};
    for (int i=0; i< NB; i++) {
        for (int j=0; j< MB; j++) {
            std::cin >> mat_b[i][j];
        }
    }

    int mat_c[NA][MB] = {0,};

    for (int i=0; i< NA; i++) {
        for (int j=0; j< MB; j++) {
            mat_c[i][j] = 0;
            for (int k=0; k< NB; k++) {
                mat_c[i][j] += mat_a[i][k]*mat_b[k][j];
            } 
        }
    }
    for (int i=0; i< NA; i++) {
        for (int j=0; j< MB; j++) {
            std::cout << mat_c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}