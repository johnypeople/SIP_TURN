# SIP_TURN
Training basics concepts of SIP/TURN protocols.

# SIP Project

Este projeto simula a troca de mensagens SIP e inclui conceitos básicos de TURN/STUN e uma API REST.

## Estrutura do Projeto

sip_project/
├── include/
│ ├── SIPMessage.h
│ ├── STUN.h
│ └── Server.h
├── src/
│ ├── SIPMessage.cpp
│ ├── STUN.cpp
│ └── Server.cpp
├── main.cpp
├── CMakeLists.txt
└── README.md

## Requisitos

- CMake 3.10 ou superior
- C++11 ou superior
- cpprestsdk
- Boost

## Compilação

```sh
mkdir build
cd build
cmake ..
make
```

# Execução


./sip_server
Uso Para enviar uma mensagem SIP:

curl -X POST -H "Content-Type: application/json" -d '{"type": "INVITE", "from": "user1", "to": "user2"}' http://localhost:8080


Para obter endereços públicos e de relay usando STUN/TURN:


curl "http://localhost:8080?address=privateAddress"


## 4. Compilar e Executar

1. **Crie um diretório de build:**

```sh
mkdir build
cd build
```

Configure o CMake:

cmake ..

Compile o projeto:

make

Execute o servidor:

./sip_server


## 5. Testar a API REST

Use curl para testar a API REST do servidor.

Enviar uma mensagem SIP:

curl -X POST -H "Content-Type: application/json" -d '{"type": "INVITE", "from": "user1", "to": "user2"}' http://localhost:8080
Obter endereços públicos e de relay usando STUN/TURN:

curl "http://localhost:8080?address=privateAddress"