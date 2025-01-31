# 🚦 Semáforo com Timer Repetitivo

Este projeto simula um sistema de semáforo utilizando um Raspberry Pi Pico W. Os LEDs alternam entre vermelho, amarelo e verde automaticamente a cada 9 segundos, utilizando a função `add_repeating_timer_ms()`.

## 🔧 Como funciona?
- O sistema inicia com todos os LEDs apagados.
- Um temporizador é configurado para chamar a função `repeating_timer_callback` a cada 9 segundos.
- O semáforo segue o ciclo padrão:
  - Verde aceso por 3 segundos.
  - Vermelho aceso por 3 segundos.
  - Amarelo aceso por 3 segundos.
- O processo se repete continuamente.

## 📌 Hardware necessário
- Raspberry Pi Pico W
- LEDs (Vermelho, Amarelo, Verde)
- Resistores (220Ω)
- Protoboard e jumpers

## 🛠️ Configuração do Ambiente
### 1️⃣ Instalar o **Visual Studio Code**
- Baixe e instale: [Visual Studio Code](https://code.visualstudio.com/).
- Adicione a extensão [Wokwi](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode) para simulação.

### 2️⃣ Instalar o **CMake**
- Baixe o instalador: [CMake](https://cmake.org/download/).
- Marque **"Add CMake to the system PATH"** durante a instalação.

### 3️⃣ Instalar o **GCC para ARM**
- Baixe a ferramenta em: [GCC ARM Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm).
- Adicione ao `PATH` do sistema:
  ```
  C:\Program Files (x86)\Arm GNU Toolchain\<versão>\bin
  ```

### 4️⃣ Instalar o **Pico SDK**
- Baixe aqui: [Pico Setup Windows](https://github.com/raspberrypi/pico-setup-windows).

## 🔌 Testando em um Raspberry Pi Pico
1. Instale o [Zadig](https://zadig.akeo.ie/) para configurar os drivers.
2. Para comunicação serial, instale o [PuTTY](https://www.putty.org/).
3. Compile e faça o upload do código para a placa.

## 📜 Código Principal (resumo)
```c
add_repeating_timer_ms(9000, repeating_timer_callback, NULL, &timer);
```
O temporizador chama `repeating_timer_callback` a cada 9 segundos para alternar os LEDs.
