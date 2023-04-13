#include "Mapping.h"

Mapping::Mapping(shared_ptr<ConfigMappingReader> mr)
{
   setup = mr;
}


vec3 Mapping::mapeigPunt(vec3 puntMonReal) {

      vec3 puntMonVirtual;

      puntMonVirtual.x = (((puntMonReal.x - this->setup->Rxmin) / (this->setup->Rxmax - this->setup->Rxmin)) *
                         (this->setup->Vxmax - this->setup->Vxmin)) + this->setup->Vxmin;
      puntMonVirtual.y = puntMonReal.y;
      puntMonVirtual.z = (((puntMonReal.z - this->setup->Rzmin) / (this->setup->Rzmax - this->setup->Rzmin)) *
                         (this->setup->Vzmax - this->setup->Vzmin)) + this->setup->Vzmin;
      puntMonVirtual.z = -puntMonVirtual.z;
      /*
      if (this->setup->Rymax != this->setup->Rymin)
         puntMonVirtual.y = (((puntMonReal.y - this->setup->Rymin) / (this->setup->Rymax - this->setup->Rymin)) *
                            (this->setup->Vymax - this->setup->Vymin)) + this->setup->Vymin;*/

      std::cout << "a" << endl;
      std::cout << puntMonVirtual.y << endl;

      return puntMonVirtual;
}

float Mapping::mapeigValor(float valorMonReal) {

    double valorMonVirtual;

    //valorMonVirtual = (valorMonReal - this->setup->Rxmin) / (this->setup->Rxmax - this->setup->Rxmin);
    valorMonVirtual = valorMonReal;
    return valorMonVirtual;
}

float Mapping::mapeigValor(float valorMonReal, int i) {

    double valorMonVirtual;
    valorMonVirtual = (valorMonReal - this->setup->propLimits[i].first) /
                      (this->setup->propLimits[i].second - this->setup->propLimits[i].first);

    return valorMonVirtual;
}

shared_ptr<ColorMap> Mapping::getColorMap(ColorMapStatic::ColorMapType tCM) {
   shared_ptr<ColorMapStatic> cm = make_shared<ColorMapStatic>(tCM);
   return cm;
}

shared_ptr<Material> Mapping::mapeigMaterial(int i, ColorMapStatic::ColorMapType tCM, double valorMonReal) {

    auto cm = getColorMap(tCM);
    int idx = 255*int(valorMonReal/(setup->propLimits[i].second-setup->propLimits[i].first));
    //return make_shared<Material>(cm->getColor(idx));
    return make_shared<Material>();
}
