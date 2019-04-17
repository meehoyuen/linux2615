#ifndef ARCH_X86_KVM_X86_H
#define ARCH_X86_KVM_X86_H

#include <linux/kvm_host.h>

static inline void kvm_clear_exception_queue(struct kvm_vcpu *vcpu)
{
	vcpu->arch.exception.pending = 0;
}

static inline void kvm_queue_interrupt(struct kvm_vcpu *vcpu, u8 vector)
{
	vcpu->arch.interrupt.pending = 1;
	vcpu->arch.interrupt.nr = vector;
}

static inline void kvm_clear_interrupt_queue(struct kvm_vcpu *vcpu)
{
	vcpu->arch.interrupt.pending = 0;
}

#endif
