///ns.h
//

#ifndef NS_H
#define NS_H

#include <memory>

namespace rtcm
{
enum class VadModel { Zero=0, One, Two, Three };

//Receives 10 ms frames audio.
class VadProcessor
{
public:
    VadProcessor()=default;

    using vad_ptr = std::shared_ptr<VadProcessor>;
    static vad_ptr create(VadModel m);

    VadProcessor(const VadProcessor&) = delete;
    VadProcessor& operator=(const VadProcessor&) = delete;

    virtual ~VadProcessor()=default;

    virtual void setModel(VadModel m) = 0;
    
    //@return ture if activity, otherwise false
    virtual bool process(int16_t* audio, size_t nframes, size_t sample_rate_hz)=0;
};
}
#endif //NS_H
