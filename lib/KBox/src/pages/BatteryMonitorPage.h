/*
  The MIT License

  Copyright (c) 2016 Thomas Sarlandie thomas@sarlandie.net

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include "MFD.h"
#include "KMessage.h"

class BatteryMonitorPage : public Page, public KReceiver {
  private:
    bool needsPainting;
    bool needsFullPainting;

    float houseVoltage;
    float houseCurrent;
    bool displayHouseVoltage = false;
    bool displayHouseCurrent = false;
    bool houseCharging;

    bool displayStarterVoltage;
    float starterVoltage;

    // We will always display this one.
    float supplyVoltage;

    Color colorForVoltage(float v);
    const char* formatMeasurement(float measure, const char *unit, bool valid = true);

  public:
    void paint(GC &context);
    bool processEvent(const Event) { return true; };
    void processMessage(const KMessage& message);

    void willAppear();
};