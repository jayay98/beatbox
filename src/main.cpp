#include <iostream>
#include <sndfile.hh>
#include <Eigen/Dense>
#include <matplotlibcpp.h>
namespace plt = matplotlibcpp;

int main () {
    // Initiation
    const char* file = "sample.wav";
    const int FRAME_SIZE = 1024;
    std::cout << "Reading file at: " << file << std::endl;

    // Reading file with sndfile
    SndfileHandle waveFile(file);
    std::cout << "Sampling rate: " << waveFile.samplerate() << std::endl;
    std::cout << "Number of frames in file: " << waveFile.frames() << std::endl;

    // Read signal into buffer
    int n_frames = waveFile.frames();
    // double* buffer = new double[n_frames];
    // waveFile.readf(buffer, n_frames);

    // Importing data from sndfile into Matrix
    // Eigen::Map<Eigen::VectorXd> vec(buffer, n_frames);
    // vec.normalize();

    std::vector<double> t, signal;
    double* buffer = new double[1];
    for (int i = 0; i <= n_frames; i += 1) {
        t.push_back(i);
        waveFile.readf(buffer, 1);
        signal.push_back(*buffer);

        if (i % 10 == 0) {
            plt::clf();
            plt::plot(t, signal);
            plt::pause(0.001);
        }
    }

    return 0;
}