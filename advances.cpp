int randomInt1(int min, int max)
{
   int num = (rand() % (max - min)) + min;
   return num;
}
double randomFloat1(double min, double max)
{
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   return num;
}


void advanceSinker(Bird* pBird) {
   // Update velocity
   Velocity newVelocity = pBird->getVelocity();
   newVelocity.addDy(-.07);
   pBird->setVelocity(newVelocity);


   // Update position
   Position newPosition = pBird->getPosition();
   newPosition.add(pBird->getVelocity());
   pBird->setPosition(newPosition);


   // Check if the bird is out of bounds
   if (pBird->isOutOfBounds()) {
      pBird->kill();                    // Kill the bird
      pBird->setPoints(-pBird->getPoints());  // Negate the points
   }
}

void advanceFloater(Bird* pBird) {
   // Update velocity
   Velocity newVelocity = pBird->getVelocity();
   newVelocity *= .990;
   newVelocity.addDy(.05);
   pBird->setVelocity(newVelocity);

   // Update position
   Position newPosition = pBird->getPosition();
   newPosition.add(pBird->getVelocity());
   pBird->setPosition(newPosition);

   // Check if the bird is out of bounds
   if (pBird->isOutOfBounds()) {
      pBird->kill();                    // Kill the bird
      pBird->setPoints(-pBird->getPoints());  // Negate the points
   }
}
void advanceStandard(Bird* pBird) {
   // Update velocity
   Velocity newVelocity = pBird->getVelocity();
   newVelocity *= .995;
   pBird->setVelocity(newVelocity);


   // Update position
   Position newPosition = pBird->getPosition();
   newPosition.add(pBird->getVelocity());
   pBird->setPosition(newPosition);

   // Check if the bird is out of bounds
   if (pBird->isOutOfBounds()) {
      pBird->kill();                    // Kill the bird
      pBird->setPoints(-pBird->getPoints());  // Negate the points
   }
}

void advanceCrazy(Bird* pBird) {
   // Update velocity
   if (randomInt1(0, 15) == 0)
   {
      pBird->getVelocity().addDy(randomFloat1(-1.5, 1.5));
      pBird->getVelocity().addDx(randomFloat1(-1.5, 1.5));
   }

   // Update position
   Position newPosition = pBird->getPosition();
   newPosition.add(pBird->getVelocity());
   pBird->setPosition(newPosition);

   // Check if the bird is out of bounds
   if (pBird->isOutOfBounds()) {
      pBird->kill();                    // Kill the bird
      pBird->setPoints(-pBird->getPoints());  // Negate the points
   }
}