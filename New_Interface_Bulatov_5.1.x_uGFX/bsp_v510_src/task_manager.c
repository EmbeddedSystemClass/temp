#include "task_manager.h"


// ����-��������� �����.
// �� 32 ����� (1 ��� = 1 ������).
// ���=1 - ��������� ����������, ���=0 - ��������� ����������.
// ���� ������ ������ ����������� ����������, �� � ����� ������ ��� ������ ���� �������� ���� ����.
// ���� ���������� ������������ ���������� ������, �� ����� ����� ���������� ���������� ������, ������� ���������� ����.
u32 tasks = TASK_NONE;	// ������, ����������� ��� ������� �������

