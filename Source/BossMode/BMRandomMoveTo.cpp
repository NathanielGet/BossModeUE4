// Fill out your copyright notice in the Description page of Project Settings.


#include "BMRandomMoveTo.h"
#include "NavigationSystem.h" 
#include "BMAIController.h"

EBTNodeResult::Type UBMRandomMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ThisTree == nullptr || ThisController == nullptr)
	{
		ThisTree = OwnerComp.GetCurrentTree();

		ThisController = Cast<ABMAIController>(OwnerComp.GetAIOwner());

		if (ThisTree == nullptr || ThisController == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Task assigned to incorrect AI type"));
			return EBTNodeResult::Failed;
		}
	}

	FNavLocation RandomPoint;
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (NavSystem->GetRandomPointInNavigableRadius(ThisController->GetPawn()->GetActorLocation(), 5000.0f, RandomPoint))
	{
		ThisController->MoveTo(RandomPoint.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}