# two-photons-data-transfer
Two different approaches in sending data from one Particle Photon to another at 100 sample/s data rate, using (1) basic UDP communication or (2) with Particle's publish/subscribe methods.

I needed to send audio-derived data from one Particle Photon to another using WiFi network. As I do some data analysis and transformation on the device that records the audio, essentialy to get the mean audio level to be displayed as an LED vu-meter on the second Photon, I only need to transfer a hundred of data (each being an 8-bit number) per second.

I implemented a basic UDP sender/receiver but then I realized that I could use the publish/subscribe cloud functions. Indeed Particle.publish() can send up to 1 message per second with optional data of max 255 byte and I needed to transfer a hundred of data per second where each data is a 8-bit number.
The only thing I had to take care of has been to encode a sequence of 8-bit numbers (the payload) as a Particle String (or as a C const char *)  and then to convert those back to an array of integers.

In the following you may find a basic UDP sender/receiver and a basic Particle.publish()/Particle.subscribe() sender/receiver.

I'm still working on the project, so those are the starting points, as I go on I will publish the updates.
