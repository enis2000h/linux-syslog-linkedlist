# linux-syslog-linkedlist
# Linux Syslog Management with Linked List

Bu proje, Linux işletim sistemindeki **Syslog** mekanizmasını temel alan ve verileri **Tek Yönlü Bağlı Liste (Singly Linked List)** veri yapısı ile işleyen bir C uygulamasıdır.

## 📝 Proje Hakkında
Bu çalışma, sistem günlüklerinin dinamik bir veri yapısı olan bağlı liste ile nasıl yönetilebileceğini göstermek amacıyla hazırlanmıştır. 

### Syslog Nedir?
Syslog, sistemde meydana gelen olayların (kernel mesajları, kullanıcı girişleri, servis hataları vb.) kronolojik olarak kaydedildiği bir standarttır.

### Neden Bağlı Liste?
- **Dinamik Bellek Yönetimi:** Log verilerinin boyutu önceden bilinmediği için sabit boyutlu diziler yerine, çalışma zamanında (`malloc` ile) genişleyebilen bağlı liste yapısı tercih edilmiştir.
- **Performans:** Yeni gelen logların listenin sonuna eklenmesi $O(n)$ veya bir `tail` işaretçisi ile $O(1)$ sürede yapılarak sistem performansı korunur.
- **Kronolojik Uyumluluk:** Bağlı listeler, logların doğal akışına (eskiden yeniye) tam uyum sağlar.

## 🚀 Özellikler
- **Dinamik Ekleme:** Her yeni log için bellekte özel bir düğüm (node) oluşturulur.
- **Otomatik Zaman Damgası:** `time.h` kütüphanesi ile logların oluşturulma saati sisteme kaydedilir.
- **Kategorizasyon:** Mesajlar `INFO`, `WARNING`, `ERROR` gibi seviyelere göre tutulur.
- **Bellek Temizliği:** Program sonlanırken kullanılan tüm bellek `free()` fonksiyonu ile iade edilir.

## 🛠️ Kurulum ve Çalıştırma
1. Bu depoyu klonlayın veya `.c` dosyasını indirin.
2. **Dev-C++** veya herhangi bir C derleyicisi ile dosyayı açın.
3. `F11` tuşuna basarak derleyin ve çalıştırın.

## 💻 Kullanılan Teknolojiler
- **Dil:** C
- **IDE:** Dev-C++
- **Veri Yapısı:** Singly Linked List (Tek Yönlü Bağlı Liste)
