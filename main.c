//*****************************************************
//
// CasaComTransRotEsc.cpp
// Um programa OpenGL simples que abre uma janela GLUT,
// translada, rotaciona e troca a escala de um casa para
// depois desenha-la.
//
// Marcelo Cohen e Isabel H. Manssour
// Este código acompanha o livro
// "OpenGL - Uma Abordagem Prática e Objetiva"
//
//*****************************************************

#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DesenhaBracos(void) {}

void DesenhaTronco(void) {}

void DesenhaCabeca(void)
{
    float ang;
    float numVertices = 20;
    glColor3f(0.0f, 0.0f, 1.0f);


    glBegin(GL_LINE_LOOP);
    for(ang=0; ang<2*M_PI; ang+=M_PI/numVertices)
        glVertex2f(20*cos(ang),20*sin(ang));
    glEnd();
    glFlush();
}

void DesenhaPernas(void) {}

// Função callback de redesenho da janela de visualização
void Desenha(void)
{
    // Muda para o sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa a matriz de transformação corrente
    glLoadIdentity();

    // Limpa a janela de visualização com a cor
    // de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT);

    DesenhaCabeca();
    DesenhaTronco();
    DesenhaBracos();
    DesenhaPernas();

    // Executa os comandos OpenGL
    glFlush();
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    GLsizei largura, altura;

    // Evita a divisao por zero
    if(h == 0)
        h = 1;

    // Atualiza as variáveis
    largura = w;
    altura = h;s

    // Especifica as dimensões da Viewport
    glViewport(largura/2, altura/2, largura, altura);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (esquerda, direita, inferior,
    // superior) mantendo a proporção com a janela de visualização
    if (largura <= altura)
        gluOrtho2D (-40.0f, 40.0f, -40.0f*altura/largura, 40.0f*altura/largura);
    else
        gluOrtho2D (-40.0f*largura/altura, 40.0f*largura/altura, -40.0f, 40.0f);
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
void TeclasEspeciais(int key,int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_PAGE_UP:
        Desenha();
        break;
    case GLUT_KEY_PAGE_DOWN:
        Desenha();
        break;
    case GLUT_KEY_RIGHT:
        Desenha();
        break;
    case GLUT_KEY_LEFT:
        Desenha();
        break;
    case GLUT_KEY_UP:
        Desenha();
        break;
    case GLUT_KEY_DOWN:
        Desenha();
        break;
    case GLUT_KEY_HOME:
        Desenha();
        break;
    case GLUT_KEY_END:
        Desenha();
        break;
    }
}

// Programa Principal
int main(void)
{
    // Define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Especifica a posição inicial da janela GLUT
    glutInitWindowPosition(5,5);

    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(450,450);

    // Cria a janela passando como argumento o título da mesma
    glutCreateWindow("Trabalho em grupo");

    // Registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(Desenha);

    // Registra a função callback de redimensionamento da janela de visualização
    glutReshapeFunc(AlteraTamanhoJanela);

    // Registra a função callback para tratamento das teclas ASCII
    glutKeyboardFunc (Teclado);

    // Chama a função responsável por fazer as inicializações
    Inicializa();
    glutSpecialFunc(TeclasEspeciais);

    // Inicia o processamento e aguarda interações do usuário
    glutMainLoop();

    return 0;
}
