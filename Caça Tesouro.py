import numpy as np

mapa = np.random.randint(1, 10, size=(5, 5))

while True:
    tesouro_linha, tesouro_coluna = np.random.randint(0, 5, size=2)
    if (tesouro_linha, tesouro_coluna) != (0, 0):
        break

posicao_player = (0, 0)
pontuacao = 0

def mostrar_mapa(mapa, posicao_player):
    mapa_jogador = mapa.copy()
    linha, coluna = posicao_player
    mapa_jogador[linha, coluna] = -1

    mapa_jogador_str = np.char.mod('%2d', mapa_jogador)
    mapa_jogador_str[mapa_jogador == -1] = 'P'

    print("\nMapa Atual:")
    for linha in mapa_jogador_str:
        print(" ".join(linha))


while True:
    mostrar_mapa(mapa, posicao_player)
    direcao = input("Qual a direção que deseja ir? (cima, baixo, direita, esquerda): ")

    movimentos = {
        "cima": (-1, 0),
        "baixo": (1, 0),
        "direita": (0, 1),
        "esquerda": (0, -1),
        "w": (-1, 0),
        "s": (1, 0),
        "d": (0, 1),
        "a": (0, -1)
    }

    if direcao in movimentos:
        nova_posicao = (posicao_player[0] + movimentos[direcao][0],
                        posicao_player[1] + movimentos[direcao][1])
    else:
        print("Tente outra direção...")
        continue

    if not (0 <= nova_posicao[0] < mapa.shape[0] and 0 <= nova_posicao[1] < mapa.shape[1]):
        print("Movimento fora dos limites. Tente de novo.")
        continue

    posicao_player = nova_posicao
    pontuacao += 1

    if posicao_player == (tesouro_linha, tesouro_coluna):
        mostrar_mapa(mapa, posicao_player)
        print("\n\nTESOURO ENCONTRADO!!\nVOCÊ VENCEU!!")
        print(f"Pontuação final: {pontuacao}")
        print(f"O tesouro estava na posição: {(tesouro_linha, tesouro_coluna)}")
        break
