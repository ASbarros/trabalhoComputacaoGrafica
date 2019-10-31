//*****************************************************
//
// CasaComTransRotEsc.cpp
// Um programa OpenGL simples que abre uma janela GLUT,
// translada, rotaciona e troca a escala de um casa para
// depois desenha-la.
//
// Marcelo Cohen e Isabel H. Manssour
// Este c�digo acompanha o livro
// "OpenGL - Uma Abordagem Pr�tica e Objetiva"
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

// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void)
{
    // Muda para o sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa a matriz de transforma��o corrente
    glLoadIdentity();

    // Limpa a janela de visualiza��o com a cor
    // de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT);

    DesenhaCabeca();
    DesenhaTronco();
    DesenhaBracos();
    DesenhaPernas();

    // Executa os comandos OpenGL
    glFlush();
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    GLsizei largura, altura;

    // Evita a divisao por zero
    if(h == 0)
        h = 1;

    // Atualiza as vari�veis
    largura = w;
    altura = h;s

    // Especifica as dimens�es da Viewport
    glViewport(largura/2, altura/2, largura, altura);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de sele��o (esquerda, direita, inferior,
    // superior) mantendo a propor��o com a janela de visualiza��o
    if (largura <= altura)
        gluOrtho2D (-40.0f, 40.0f, -40.0f*altura/largura, 40.0f*altura/largura);
    else
        gluOrtho2D (-40.0f*largura/altura, 40.0f*largura/altura, -40.0f, 40.0f);
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualiza��o como branca
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
    // Define do modo de opera��o da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Especifica a posi��o inicial da janela GLUT
    glutInitWindowPosition(5,5);

    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(450,450);

    // Cria a janela passando como argumento o t�tulo da mesma
    glutCreateWindow("Trabalho em grupo");

    // Registra a fun��o callback de redesenho da janela de visualiza��o
    glutDisplayFunc(Desenha);

    // Registra a fun��o callback de redimensionamento da janela de visualiza��o
    glutReshapeFunc(AlteraTamanhoJanela);

    // Registra a fun��o callback para tratamento das teclas ASCII
    glutKeyboardFunc (Teclado);

    // Chama a fun��o respons�vel por fazer as inicializa��es
    Inicializa();
    glutSpecialFunc(TeclasEspeciais);

    // Inicia o processamento e aguarda intera��es do usu�rio
    glutMainLoop();

    return 0;
}
