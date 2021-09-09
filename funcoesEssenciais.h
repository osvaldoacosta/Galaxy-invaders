#ifndef FUNCOES_ESSENCIAIS
#define FUNCOES_ESSENCIAIS

void gotoxy(int x, int y);
void limparBuffer();
void valoresPadroesCanhao();
void valoresPadroesProjetil();
void valoresPadroesDisco1();
void valoresPadroesDisco2();
void valoresPadroesDisco3();
void valoresPadroes();
void randomizador(float *rc, float *rb);
void modoDebug();
void escondeCursor();
int tempoLoop(int tempoJogo);
void borda();
void redimensionarTela();

void msSleep(long miliseg);
#endif
