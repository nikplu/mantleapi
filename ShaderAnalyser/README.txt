This is a re-upload of the software found at
http://www.hlsl.co.uk/blog/2014/10/9/updated-shader-analyser-with-amd-il-support
with which you can compile HLSL into AMD IL to run your shader code on Mantle-capable GPUs.
This is proprietary software, I use it only under the conditions of Fair Use (US copyright law) for the purpose of personal education.

Code your vertex/pixel shader in HLSL, then compile it using CodeXLAnalyzer or the Shader Analyser GUI, then convert the resulting IL to binary using output2binary. The command line to use for CodeXLAnalyzer looks like this (courtesy of github.com/Overv)

CodeXLAnalyzer.exe -c Hawaii -f VShader -s HLSL -p vs_5_0 --il vs_il.txt vs.hlsl

for a vertex shader, for example.
