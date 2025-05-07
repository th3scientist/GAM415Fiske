// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeDMI.h"
#include "GAM415FiskeCharacter.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACubeDMI::ACubeDMI()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>("Box Component");
	cubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("Cube Mesh");

	RootComponent = boxComp;
	cubeMesh->SetupAttachment(boxComp);

}

// Called when the game starts or when spawned
void ACubeDMI::BeginPlay()
{
	Super::BeginPlay();

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ACubeDMI::OnOverlapBegin);

	if (baseMat)
	{
		dmiMat = UMaterialInstanceDynamic::Create(baseMat, this);
	}
	if (cubeMesh)
	{
		cubeMesh->SetMaterial(0, dmiMat);
	}
	
}

// Called every frame
void ACubeDMI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeDMI::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGAM415FiskeCharacter* overlappedActor = Cast<AGAM415FiskeCharacter>(OtherActor);

	if (overlappedActor) 
	{
		float ranNumX = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
		float ranNumY = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
		float ranNumZ = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
		FVector4 randColor = FVector4(ranNumX, ranNumY, ranNumZ, 1.0f);

		if (dmiMat)
		{
			dmiMat->SetVectorParameterValue("Color", randColor);
			dmiMat->SetScalarParameterValue("Intensity", UKismetMathLibrary::RandomFloatInRange(0.0f, 100.0f));
			dmiMat->SetScalarParameterValue("Opacity", UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f));
		}
	}
}

