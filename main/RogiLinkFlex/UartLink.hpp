#include <Arduino.h>
#include "RogiLinkFlex/CommunicationBase.hpp"

// UartLinkクラス。CobsEncodedCommunicationBaseを継承
class UartLink : public CobsEncodedCommunicationBase {
    public:
        UartLink(HardwareSerial& serial, uint8_t device_id=0);

        // 送信処理
        void send_raw(uint8_t* data, uint8_t size) override;

        // 受信処理
        void loop();

    private:
        HardwareSerial& uart;
        uint8_t receive_buffer[BUFFER_SIZE];
        uint8_t receive_buffer_index = 0;
};

// Publisher
template<typename... Args>
using UartLinkPublisher = Publisher<UartLink, Args...>;

// Subscriber
template<typename... Args>
using UartLinkSubscriber = Subscriber<UartLink, Args...>;