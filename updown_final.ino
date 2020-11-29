/* Edge Impulse Arduino examples
 * Copyright (c) 2020 EdgeImpulse Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* Includes ---------------------------------------------------------------- */
#include <wisblock-accelerometer_inference.h>

static const float features[] = {
    3.3600, 0.4500, 5.6100, 3.6400, 0.3800, 7.4700, 2.6100, -0.8300, 9.8500, 2.6100, -0.8300, 9.8500, 1.1800, -1.8600, 10.1100, 1.5000, -1.1300, 10.7700, 2.6800, 1.0800, 10.9200, 2.6100, 2.5900, 11.0300, 1.5400, 1.8400, 12.2600, 0.5200, 1.0200, 12.1500, 0.5200, 1.0200, 12.1500, 0.0800, 0.9100, 10.5900, 0.3200, 0.7600, 11.5300, 0.7400, 2.9600, 13.8700, 1.0600, 3.7200, 12.6800, 1.0000, 2.7400, 12.8200, 0.6400, 1.4400, 11.8400, 0.6400, 1.4400, 11.8400, -0.0300, 0.7700, 12.2900, -0.3500, 0.8400, 12.1700, -0.1700, 1.2500, 11.4500, 0.1000, 0.8400, 11.2100, 0.0500, -0.1500, 12.5200, -0.4200, -0.2400, 14.0400, -0.4200, -0.2400, 14.0400, -0.4300, 0.8200, 13.7500, 0.8800, 0.6500, 11.6300, -0.1200, 1.3900, 13.2400, -0.3900, 0.2700, 12.6800, -1.1700, 0.3900, 13.3700, 0.5500, -2.2900, 12.6800, 0.5500, -2.2900, 12.6800, -1.3400, 0.2000, 11.9400, -0.3000, -0.4800, 13.6500, -2.0500, -2.0200, 16.7400, -2.5000, -3.5200, 18.6800, -2.7800, -2.8400, 17.8500, -2.0700, -0.7000, 14.4100, -2.0700, -0.7000, 14.4100, -1.6500, 0.3300, 12.9300, -1.6700, -0.2400, 14.1700, -2.0400, -1.5500, 15.9300, -2.0500, -1.5000, 15.9200, -1.6700, -0.6100, 15.0200, -1.6700, -0.6100, 15.0200, -1.5300, -0.4400, 14.6500, -1.2300, -0.3600, 14.4100, -0.7700, -0.1400, 13.3600, -0.3100, 0.3300, 11.9800, -0.1400, 0.5000, 10.2800, 0.1200, 0.7400, 8.7300, 0.1200, 0.7400, 8.7300, 0.2200, 0.0000, 9.2900, 0.1000, -1.0400, 10.8800, -0.3700, -2.1700, 11.8400, -1.2500, -2.8900, 10.4800, -0.8600, -2.6000, 8.2600, -0.1500, -1.2200, 5.7200, -0.1500, -1.2200, 5.7200, 0.7300, 0.3500, 5.1300, 1.0700, -0.4900, 6.8100, 0.3900, -3.1100, 7.1400, 0.2500, -3.4000, 5.2900, 1.1100, -1.6000, 3.8800, 2.0500, 0.4200, 4.1200, 2.0500, 0.4200, 4.1200, 2.4900, 0.7300, 4.4900, 2.2800, -0.7700, 5.5800, 1.8200, -1.9600, 6.8900, 1.8300, -0.8100, 6.7700, 2.3300, 1.0700, 6.2100, 2.6200, 1.2200, 5.9500, 2.6200, 1.2200, 5.9500, 2.5100, 0.5400, 5.7600, 2.3900, -0.1400, 5.8500, 1.8300, -0.7300, 5.8500, 1.5800, -0.7600, 4.6100, 1.7600, 0.0500, 2.7700, 1.9900, 0.4000, 1.4600, 1.9900, 0.4000, 1.4600, 1.8100, -1.1500, 1.1500, 1.3600, -2.6700, 2.5200, 1.2700, -2.7700, 4.4300, 1.5400, -2.8100, 4.1900, 1.8200, -1.6800, 3.4400, 1.7400, -0.1600, 4.0000, 1.7400, -0.1600, 4.0000, 1.5000, -0.5500, 5.4400, 1.2200, -2.7200, 7.5000, 1.4300, -3.7300, 8.2800, 1.5700, -2.4400, 7.3200, 1.6600, -0.8200, 6.1200, 1.6800, -1.0200, 7.2600, 1.6800, -1.0200, 7.2600, 1.0800, -2.3000, 9.9300, 0.6900, -2.3300, 10.6400, 0.8000, -1.3800, 10.1100, 1.2500, -0.8500, 9.6000, 1.3200, 0.0000, 10.5800, 1.3200, 0.0000, 13.1200, 1.1900, -0.4800, 13.1200, 1.5500, -0.7300, 12.3100, 2.0200, 1.5400, 8.3200, 2.3300, 4.1500, 8.0600, 1.1800, 2.8200, 12.3500, 0.4300, -0.2800, 17.0500, 0.4300, -0.2800, 17.0500, 0.4300, -2.0000, 14.6600, 1.1600, -0.5100, 12.0300, 1.6400, 2.2800, 10.6800, 1.7100, 2.2600, 12.9700, 1.3700, 0.5600, 15.3000, 1.4000, -0.4500, 14.4600, 1.4000, -0.4500, 14.4600, 1.5700, 0.9200, 11.5600, 1.7400, 2.1600, 9.2700, 1.4800, 1.1600, 10.8200, 0.4600, -1.1600, 14.6000, -0.0400, -1.6700, 15.1500, 0.7000, 0.5000, 12.9300, 0.7000, 0.5000, 12.9300, 1.6200, 2.3200, 9.9600, 1.0500, 2.0800, 10.9400, 0.1500, -0.7200, 14.0200, -1.2400, -3.4700, 19.7200
};

/**
 * @brief      Copy raw feature data in out_ptr
 *             Function called by inference library
 *
 * @param[in]  offset   The offset
 * @param[in]  length   The length
 * @param      out_ptr  The out pointer
 *
 * @return     0
 */
int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}


/**
 * @brief      Arduino setup function
 */
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);

    Serial.println("Edge Impulse Inferencing Demo");
}

/**
 * @brief      Arduino main function
 */
void loop()
{
    ei_printf("Edge Impulse standalone inferencing (Arduino)\n");

    if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
        ei_printf("The size of your 'features' array is not correct. Expected %lu items, but had %lu\n",
            EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
        delay(1000);
        return;
    }

    ei_impulse_result_t result = { 0 };

    // the features are stored into flash, and we don't want to load everything into RAM
    signal_t features_signal;
    features_signal.total_length = sizeof(features) / sizeof(features[0]);
    features_signal.get_data = &raw_feature_get_data;

    // invoke the impulse
    EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false /* debug */);
    ei_printf("run_classifier returned: %d\n", res);

    if (res != 0) return;

    // print the predictions
    ei_printf("Predictions ");
    ei_printf("(DSP: %d ms., Classification: %d ms., Anomaly: %d ms.)",
        result.timing.dsp, result.timing.classification, result.timing.anomaly);
    ei_printf(": \n");
    ei_printf("[");
    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        ei_printf("%.5f", result.classification[ix].value);
#if EI_CLASSIFIER_HAS_ANOMALY == 1
        ei_printf(", ");
#else
        if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
            ei_printf(", ");
        }
#endif
    }
#if EI_CLASSIFIER_HAS_ANOMALY == 1
    ei_printf("%.3f", result.anomaly);
#endif
    ei_printf("]\n");

    // human-readable predictions
    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        ei_printf("    %s: %.5f\n", result.classification[ix].label, result.classification[ix].value);
    }
#if EI_CLASSIFIER_HAS_ANOMALY == 1
    ei_printf("    anomaly score: %.3f\n", result.anomaly);
#endif

    delay(1000);
}

/**
 * @brief      Printf function uses vsnprintf and output using Arduino Serial
 *
 * @param[in]  format     Variable argument list
 */
void ei_printf(const char *format, ...) {
    static char print_buf[1024] = { 0 };

    va_list args;
    va_start(args, format);
    int r = vsnprintf(print_buf, sizeof(print_buf), format, args);
    va_end(args);

    if (r > 0) {
        Serial.write(print_buf);
    }
}
