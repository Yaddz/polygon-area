#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define estrutura de dados para as cordenadas dos pontos
typedef struct{
    float X;
    float Y;
} Ponto;

//calculo da área de cada triangulo usando determinante 
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float M[3][3] = {
        {A.X, A.Y, 1.00},
        {B.X, B.Y, 1.00},
        {C.X, C.Y, 1.00} 
    };

    float AreaT = 0;
    AreaT = AreaT + M[0][0] * M[1][1] * M[2][2];
    AreaT = AreaT + M[0][1] * M[1][2] * M[2][0];
    AreaT = AreaT + M[0][2] * M[1][0] * M[2][1];
    AreaT = AreaT - M[2][0] * M[1][1] * M[0][2];
    AreaT = AreaT - M[2][1] * M[1][2] * M[0][0];
    AreaT = AreaT - M[2][2] * M[1][0] * M[0][1];

    //arrendondando resultado do determinante
    float AreaTotal = (round(AreaT/2 * 10) / 10);

    // Apenas testando...
    //printf("%.2f\n", fabs(AreaTotal));
    return AreaTotal;
}

int main(){
    FILE *Dados;
    int NumVertices;
    float SomaAreas = 0.0;
    
    Dados = fopen("vertices.txt", "r");
    if (Dados == NULL) {
        printf("Não foi possivel abrir o arquivo de entrada.");
        return 1;
    }

    //ler o numero de vertices e converte para triangulos para completar a área do poligono
    fscanf(Dados, "%d", &NumVertices);
    NumVertices = NumVertices - 2;

    Ponto Vertices[3];

    //Loop para ler os dados de entrada e chamar a função para calculo de cada triangulo
    for(int i = 0; i < NumVertices; i++){
        for(int j = 0; j < 3; j++){
        fscanf(Dados, "%f %f", &Vertices[j].X, &Vertices[j].Y);  
        }
        //Soma de todas as áreas :)
        SomaAreas += AreaTriangulo(Vertices[0], Vertices[1], Vertices[2]);          
    }

    fclose(Dados);

    printf("Área total do poligono: %.2f", fabs(SomaAreas));
}