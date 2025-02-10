#include <curses.h>
#include <stdlib.h>

//Constastes das teclas ENTER e ESCAPE.
#define ENTER 10
#define ESCAPE 27

void criarmenu(WINDOW *menubar)  //Função encarregada de criar um menu em nosso sistema
{
   
    //wmove(menubar,0,50);            // Posiciona o cursor na linha 0, coluna 20
    waddstr(menubar,"MENU GOSTOSO DA PORRA");
    wattron(menubar,COLOR_PAIR(3));
    waddstr(menubar," F3 ");
    wattroff(menubar,COLOR_PAIR(3));
}

WINDOW **criaritensmenu(int coluna)  //Desenha os ítens do menu quando as teclas F1 ou F2 for pressionada
{
/*
  +--------------------------------------------------------------------------------------------+
  |   - Cria uma janela itensmenu[0] para desenhar uma caixa à volta do menu.                  |
  |   - Cria 8 ítens como sub-janelas da janela itensmenu[0].                                  |
  |   - Os 8 ítens são criados para poder mostrar o ítem selecionado no menu.                  |
  |   - Para um ítem de menu parecer selecionado basta tornar a sua cor de fundo diferente.    |
  +--------------------------------------------------------------------------------------------+
*/
    int i;
    WINDOW **itensmenu;
    itensmenu=(WINDOW **)malloc(7*sizeof(WINDOW *));//

    itensmenu[0]=newwin(8,19,1,coluna);
    wbkgd(itensmenu[0],COLOR_PAIR(2));
    box(itensmenu[0],ACS_VLINE,ACS_HLINE);
    itensmenu[1]=subwin(itensmenu[0],1,17,2,coluna+1);//
    itensmenu[2]=subwin(itensmenu[0],1,17,3,coluna+1);//
    itensmenu[3]=subwin(itensmenu[0],1,17,4,coluna+1);//
    itensmenu[4]=subwin(itensmenu[0],1,17,5,coluna+1);//
    itensmenu[5]=subwin(itensmenu[0],1,17,6,coluna+1);
    itensmenu[6]=subwin(itensmenu[0],1,17,7,coluna+1);
    //itensmenu[7]=subwin(itensmenu[0],1,17,8,coluna+1);
    //itensmenu[8]=subwin(itensmenu[0],1,17,9,coluna+1);
    for (i=1;i<7;i++) {
        if (i==1) {
            wprintw(itensmenu[i],"Interacao");
        } else if (i==2) {
            wprintw(itensmenu[i],"Aleatorio");
        } else if (i==3) {
            wprintw(itensmenu[i],"Ver matriz");
        } else if (i==4) {
            wprintw(itensmenu[i],"Colorir");
        } else if (i==5) {
            wprintw(itensmenu[i],"Organizar");
        } else if (i==6) {
            wprintw(itensmenu[i],"Imprimir");
        }
    }
    wbkgd(itensmenu[1],COLOR_PAIR(1));
    wrefresh(itensmenu[0]);
    return itensmenu;
}




void deletaritensmenu(WINDOW **itensmenu,int numeroitens) //Apaga os ítens da menu criado pela função acima
{
    int i;
    for (i=0;i<numeroitens;i++)
        delwin(itensmenu[i]);
    free(itensmenu);
}

int scrollmenu(WINDOW **itensmenu, int numeroitens, int colunainicial) //Permite fazer scroll entre e dentro dos menus
{
/*
  +--------------------------------------------------------------------------------------------+
  |- Lê as funções pressionadas com a função getch.                                            |
  |- Se as setas baixo ou cima são pressionadas então os ítens abaixo ou acima são seleciona- |
  |  dos tornando a cor do fundo do ítens diferente dos demais.                                |
  |- Se as setas direita ou esquerda são pressionadas então o menu aberto é fechado e o outro |
  |  é aberto.                                     |
  |- Se a tecla ENTER for pressionada, então o ítem selecionado é retornado.                   |
  |- Se a tecla ESC é pressionada, os menus são fechados.                                      |
  +--------------------------------------------------------------------------------------------+
*/
    int key;
    int selecionado=0;
    while (1) 
    {
        key=getch();
        if (key==KEY_DOWN || key==KEY_UP) 
        {
            wbkgd(itensmenu[selecionado+1],COLOR_PAIR(2));
            wnoutrefresh(itensmenu[selecionado+1]);
            if (key==KEY_DOWN)
            {
                selecionado=(selecionado+1) % numeroitens;
            } else 
            {
                selecionado=(selecionado+numeroitens-1) % numeroitens;
            }
            wbkgd(itensmenu[selecionado+1],COLOR_PAIR(1));
            wnoutrefresh(itensmenu[selecionado+1]);
            doupdate();
        } 
        else if (key==KEY_LEFT || key==KEY_RIGHT) 
        {
            deletaritensmenu(itensmenu,numeroitens+1);
            touchwin(stdscr);
            refresh();
            itensmenu=criaritensmenu(20-colunainicial);
            return scrollmenu(itensmenu,8,20-colunainicial);
        } 
        else if (key==ESCAPE) 
        {
            return -1;
        } 
        else if (key==ENTER) 
        {
            return selecionado;
        }
    }
}

int main() {

/*
  +--------------------------------------------------------------------------------------------+
  |- Lê as funções pressionadas com a função getch.                                            |
  |- Se as teclas F1 ou F2 é pressionada, desenha a janela de menu correspondente com a função |
  |  criaritensmenu.                                                                           |
  |- Após isto chama a função scrollmenu e deixa o usuário fazer a seleção a partir dos menus. |
  |- Após o retorno da função scrollmenu apaga as janelas de menu e imprime o ítem selecionado |
  |  na barra de mensagem.                                 |
  |- Se a tecla ENTER for pressionada, então o ítem selecionado é retornado.                   |
  |- Se a tecla ESC é pressionada, os menus são fechados.                                      |
  +--------------------------------------------------------------------------------------------+
*/
    int key;
    int itemselecionado;
    WINDOW **itensmenu;   WINDOW **itensmenu2;
    WINDOW *menu,*mensagem;

    //Inicializações---------------------------------------------
    initscr();      //Inicializando a ncurses
    start_color();  //Tornando o uso das cores possíveis

    //Definição dos pares de cores
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);

    curs_set(0);  //Faz com que o cursor físico fique invisível.
    noecho();     //Impede que as teclas apareçam na tela
    keypad(stdscr,TRUE);  //Ativa as teclas de função
    //-----------------------------------------------------------

    bkgd(COLOR_PAIR(1));
    menu=subwin(stdscr,1,80,0,0);
    mensagem=subwin(stdscr,1,79,23,1);
    criarmenu(menu);
    refresh();

    do {
        key=getch();
        werase(mensagem);
        wrefresh(mensagem);

        if (key==KEY_F(3))
        {
            //Inserir_Aresta(alunos, tam_sala, nomes);
            itensmenu=criaritensmenu(0);
            itemselecionado=scrollmenu(itensmenu,6,0);
            deletaritensmenu(itensmenu,6);
            if (itemselecionado<0)
                wprintw(mensagem,"Nenhum ítem foi selecionado");
            else if (itemselecionado==0) {
                //InteracaoComUsuario();
            } else if (itemselecionado==1) {
                //matriz_adjacencia=aleatoriamente(tam_sala, matriz_adjacencia);
                printw("a");
            } else if (itemselecionado==2) {
                /*for (int j = 0; j < count; ++j) {
                    //move coluna
                    for (int j = 0; j < count; ++j) {
                        //impressao
                        //move linha*/
                    //}
                //}
            } else if (itemselecionado=3) {
                //graphColour(k, m, alunos, matriz_adjacencia, tam_sala);
                printw("a");
            } else if (itemselecionado==4) {
                //alunos=organizaTurma (alunos, tam_sala);
                printw("Realizado com sucesso");
            } else if (itemselecionado==5) {
                //Imprimir(alunos, tam_sala);
            }
            touchwin(stdscr);
            refresh();
        }
    } while (key!=ESCAPE);

    //desalocar_vetor (alunos);
    //desalocar_matriz (matriz_adjacencia, tam_sala);

    delwin(menu);
    delwin(mensagem);
    endwin();
    return 0;
}
