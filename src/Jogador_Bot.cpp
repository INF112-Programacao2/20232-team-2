#include "../include/Jogador_Bot.hpp"

Jogador_Bot::Jogador_Bot(std::string _nick) : Jogador(_nick)
{
}

Jogador_Bot::~Jogador_Bot()
{
}

void Jogador_Bot::funcao_teste()
{

}
bool Jogador_Bot::apostar(int &valorMesa) 
{
   int aposta = valorMesa - this->get_Apostado();

   //Se o bot já estiver apostado o valor da mesa, então ele dará check()
   if(aposta == 0)
   {
      std::cout << "O jogador " <<  get_Nick() << " apostou 0 nessa rodada.\n";
      return true;
   }

   //Em caso contrário verificaremos se ele ainda pode apostar nessa rodada
   else if(this->get_Saldo() + this->get_Apostado() >= valorMesa)
   {
      int aposta_em_fichas = 0, ficha, quantidadeFicha;
        
      for (int i = 0; i < this->get_Fichas().size(); i++)
      {
         if(this->get_Fichas()[i].second > 0)
         {
            ficha = this->get_Fichas()[i].first;
            quantidadeFicha = this->get_Fichas()[i].second;
         }
            
         aposta_em_fichas += ficha * quantidadeFicha;
         this->get_Fichas()[i].second -= quantidadeFicha;
         // se a quantidade apostada em fichas ate então suprir o valor da aposta proposta, ele finaliza com um goto endloop
         if(aposta_em_fichas >= aposta)
         {
            std::cout << "O jogador " <<  get_Nick() << " apostou " << aposta << " nessa rodada.\n";
            aposta_em_fichas -= aposta;
            set_Saldo(get_Saldo()-aposta);
            set_Apostado(this->get_Apostado() + aposta);
            valorMesa = get_Apostado();
            converte_Sobressalente(aposta_em_fichas);
            return true;
         }
      }
   }                 
    
   //Se a aposta for igual ao saldo do jogador, isso quer dizer que o jogador entrará em modo all in
   else if(!(this->is_True_All_In()))
   {
      this->set_All_In(true);
      this->set_Apostado(get_Apostado() + get_Saldo());
      std::cout << "O jogador " <<  get_Nick() << " apostou " << get_Saldo() << " nessa rodada.\n";
      std::cout << "O jogador " <<  get_Nick() << " apostou todo seu dinheiro, entrando em all in\n";
      set_Saldo(0);
      for (size_t i = 0; i < get_Fichas().size(); i++)
      {
         set_Fichas(i,0);
      }
      return true;
   }
      return false;
}


