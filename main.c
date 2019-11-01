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


///    glutTimerFunc()
///    animacao


#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DesenhaBracos(void) {
   glBegin(GL_LINES);
   glVertex2d(0,6);
   glVertex2d(-4,0);
   glEnd();

   glBegin(GL_LINES);
   glVertex2d(0,6);
   glVertex2d(4,0);
   glEnd();
}

void DesenhaTronco(void)
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2d(0,8);
    glVertex2d(0,-4);
    glEnd();
    //glFlush();
}

void DesenhaCabeca(void)
{
    float ang;
    float numVertices = 20;
    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_LINE_LOOP);
    for(ang=0; ang<2*M_PI; ang+=M_PI/numVertices)
        glVertex2f(2*cos(ang), 2*sin(ang) +10);
    glEnd();
    //glFlush();
}

void DesenhaPernas(void)
{
    glBegin(GL_LINES);
    glVertex2d(0,-4);
    glVertex2d(4,-10);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(0,-4);
    glVertex2d(-4,-10);
    glEnd();
}

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

    glLineWidth(4);

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
    altura = h;

    // Especifica as dimensões da Viewport

    glViewport(0, 0, largura, altura);
    Desenha();

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


///    glutTimerFunc()
///    animacao


#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DesenhaBracos(void) {
   glBegin(GL_LINES);
   glVertex2d(0,6);
   glVertex2d(-4,0);
   glEnd();

   glBegin(GL_LINES);
   glVertex2d(0,6);
   glVertex2d(4,0);
   glEnd();
}

void DesenhaTronco(void)
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2d(0,8);
    glVertex2d(0,-4);
    glEnd();
    //glFlush();
}

void DesenhaCabeca(void)
{
    float ang;
    float numVertices = 20;
    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_LINE_LOOP);
    for(ang=0; ang<2*M_PI; ang+=M_PI/numVertices)
        glVertex2f(2*cos(ang), 2*sin(ang) +10);
    glEnd();
    //glFlush();
}

void DesenhaPernas(void)
{
    glBegin(GL_LINES);
    glVertex2d(0,-4);
    glVertex2d(4,-10);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(0,-4);
    glVertex2d(-4,-10);
    glEnd();
}

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

    glLineWidth(4);

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
    altura = h;

    // Especifica as dimensões da Viewport

    glViewport(0, 0, largura, altura);
    Desenha();

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
        break;
    case GLUT_KEY_PAGE_DOWN:
        break;
    case GLUT_KEY_RIGHT:
        break;
    case GLUT_KEY_LEFT:
        break;
    case GLUT_KEY_UP:
        break;
    case GLUT_KEY_DOWN:
        break;
    case GLUT_KEY_HOME:
        break;
    case GLUT_KEY_END:
        break;
    }
            Desenha();

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
        break;
    case GLUT_KEY_PAGE_DOWN:
        break;
    case GLUT_KEY_RIGHT:
        break;
    case GLUT_KEY_LEFT:
        break;
    case GLUT_KEY_UP:
        break;
    case GLUT_KEY_DOWN:
        break;
    case GLUT_KEY_HOME:
        break;
    case GLUT_KEY_END:
        break;
    }
            Desenha();

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
