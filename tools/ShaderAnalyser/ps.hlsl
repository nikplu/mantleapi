struct VIn {
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

float4 PShader(VIn vin) : SV_TARGET {
    return vin.color;
}