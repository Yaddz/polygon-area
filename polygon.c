#include <stdio.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return abs(A.X*(B.Y-C.Y) + B.X*(C.Y-A.Y) + C.X*(A.Y-B.Y))/2.0;
}

int main() {
    FILE *file;
    fopen("vertices.txt", "r");

    
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    int numVertices;
    fscanf(file, "%d", &numVertices);

    Ponto vertices[numVertices];
    for (int i = 0; i < numVertices; i++) {
        fscanf(file, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(file);

    float area = 0;
    for (int i = 0; i < numVertices-2; i++) {
        area += AreaTriangulo(vertices[0], vertices[i+1], vertices[i+2]);
    }

    printf("A área do polígono é %.2f\n", area);

    return 0;
}
